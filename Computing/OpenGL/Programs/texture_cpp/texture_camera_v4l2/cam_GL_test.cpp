#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include "../../stb_image.h"
#include "v4l2_lib_cam.h"

#include "../learnopengl/shader_s.h"

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdio.h>


typedef struct {
    float x,y,z;
} IMU_3D_COORD;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;

int main()
{
    // glfw: initialize and configure
    // ------------------------------

    stbi_uc *streamBuff = NULL;
    int size = 0;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    init_v4l2_lib_stream("/dev/video0");
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // build and compile our shader zprogram
    // ------------------------------------
    Shader ourShader("vshader.vs", "fshader.fs"); 

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[] = {
        // positions          // colors           // texture coords
         1.0f,  1.0f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
         1.0f, -1.0f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
        -1.0f, -1.0f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
        -1.0f,  1.0f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
    };
    unsigned int indices[] = {  
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };
    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);


    // load and create a texture 
    // -------------------------
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);  
    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.

    capture_image( ( char ** ) &streamBuff, &size);
    std::cout << size << std::endl;
    unsigned char *data = NULL;
    data = stbi_load_from_memory( streamBuff, size, &width, &height, &nrChannels, 0);
    std::cout << width << " " << height << std::endl;
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    std::cout << "started loading IMU data from the file" << std::endl;
    std::ifstream file("/home/cibi/Documents/Learning/Github_learning/Learnings/Computing/OpenGL/Programs/texture_cpp/texture_camera_v4l2/imu_handshake_rotate_moderate.csv");
    IMU_3D_COORD *acce = NULL, 
                 *gyro = NULL;
    int n;
    int count = 7831;
    float t1, t2;

    // Allocate memory for data points
    acce = (IMU_3D_COORD *)malloc(count * sizeof(IMU_3D_COORD ));
    gyro = (IMU_3D_COORD *)malloc(count * sizeof(IMU_3D_COORD ));

    // Read data from the file
        if (file.is_open()) {
            std::cout<<"in file"<<std::endl;
            char ca;
            int  i;
            while (file >> n >>ca >> acce[i].x  >>ca>> acce[i].y  >>ca>>acce[i].z >>ca>>gyro[i].x >>ca>>gyro[i].y >>ca>>gyro[i].z >>ca>>t1 >>ca>>t2) {
            //while (file >>n) {
                 //Process the data
           //   std::cout <<" "<< n <<" "<< acce[i].x <<" "<< acce[i].y <<" "<<acce[i].z<<" "<<gyro[i].x<<" "<<gyro[i].y<<" "<<gyro[i].z<<" "<<t1<<" "<<t2<<std::endl;
              //std::cout<<i<<" ";
              i++;
            }

            file.close();
        } else {
            // Handle file opening error
            std::cout<<"error in loading data"<<std::endl;
        }
        //std::cout<<n<<" ";


    std::cout<<"started rendering"<<std::endl;
    int imuIdx = 0;
    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // bind Texture
        glBindTexture(GL_TEXTURE_2D, texture);

        capture_image( ( char ** ) &streamBuff, &size);
        data = stbi_load_from_memory( streamBuff, size, &width, &height, &nrChannels, 0);
        glTexSubImage2D( GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);

        glm::mat4 transform = glm::mat4(1.0f);
#define scale_val 0.8
        transform = glm::scale(transform, glm::vec3(scale_val, scale_val, scale_val));
        transform = glm::translate(transform, glm::vec3(acce[imuIdx].x,acce[imuIdx].y, acce[imuIdx].z));
        transform = glm::rotate(transform, (float) glm::radians(gyro[imuIdx].x), glm::vec3(1.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, (float) glm::radians(gyro[imuIdx].y), glm::vec3(0.0f, 1.0f, 0.0f));
        imuIdx+=10;
        int i = imuIdx;
          //  std::cout <<imuIdx<<" "<< n <<" "<< acce[i].x <<" "<< acce[i].y <<" "<<acce[i].z<<" "<<gyro[i].x<<" "<<gyro[i].y<<" "<<gyro[i].z<<" "<<t1<<" "<<t2<<std::endl;
        if (imuIdx >  count)
        {
            imuIdx = 0;
            std::cout<<"completed one cycle of imu data"<<std::endl;
        }
        //transform = glm::rotate(transform, glm::radians(40.0f), glm::vec3(1.0f, 0.0f, 0.0f));


        // render container
        ourShader.use();

        unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));


        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    exit_v4l2_lib_stream();
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}