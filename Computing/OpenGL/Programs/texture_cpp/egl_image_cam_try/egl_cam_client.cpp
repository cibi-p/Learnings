#define GLFW_EXPOSE_NATIVE_EGL
#define GLFW_EXPOSE_NATIVE_GLX
#define GLFW_EXPOSE_NATIVE_X11
#include "glad_gles/include/glad/glad.h"
#include "glad_gles/include/KHR/khrplatform.h"
#include "glad_egl/include/glad/glad_egl.h"
#include "glad_egl/include/EGL/eglplatform.h"
#include "glad_egl/include/KHR/khrplatform.h"
#include "shader_s_egl.h"
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#define STB_IMAGE_IMPLEMENTATION
#include "../../stb_image.h"
#include "v4l2_lib_cam.h"
#include "socket.h"

#define CLIENT
#include <iostream>


#define TEXTURE_DATA_WIDTH 1280
#define TEXTURE_DATA_HEIGHT 720

void framebuffer_size_callback(GLFWwindow*glfw_window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;

void gl_draw_scene(GLuint texture)                                                                       
{
    // clear
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
 
    // draw quad
    // VAO and shader program are already bound from the call to gl_setup_scene
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); 
}


int main()
{
    // glfw: initialize and configure
    // ------------------------------

    stbi_uc *streamBuff = NULL;
    // Set OpenGL rendering API                                                                      
    eglBindAPI(EGL_OPENGL_API);

    Display * glfw_display = glfwGetX11Display();
    EGLDisplay egl_display = eglGetDisplay(glfw_display);

    eglInitialize( egl_display, NULL, NULL );
    // get an appropriate EGL frame buffer configuration                                                 
    EGLConfig config;
    EGLint num_config;
    EGLint const attribute_list_config[] = { 
        EGL_RED_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_BLUE_SIZE, 8,
        EGL_NONE};
    eglChooseConfig(egl_display, attribute_list_config, &config, 1, &num_config);
       
    // create an EGL rendering context
    EGLint const attrib_list[] = { 
        EGL_CONTEXT_MAJOR_VERSION, 3,
        EGL_CONTEXT_MINOR_VERSION, 2,
        EGL_NONE};
    EGLContext egl_context = eglCreateContext(egl_display, config, EGL_NO_CONTEXT, attrib_list);
       

    int size = 0;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#ifndef CLIENT
    init_v4l2_lib_stream("/dev/video0");
#endif
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* glfw_window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (glfw_window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    Window window = glfwGetX11Window( glfw_window );
    EGLSurface egl_surface = eglCreateWindowSurface(egl_display,config, window, NULL);
    glfwMakeContextCurrent(glfw_window);
    glfwSetFramebufferSizeCallback(glfw_window, framebuffer_size_callback);

    eglMakeCurrent(egl_display, egl_surface, egl_surface, egl_context );
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

    glBindBuffer( GL_ARRAY_BUFFER, 0 );
    glBindVertexArray(0);

    ourShader.use();
    glBindVertexArray(VAO);

    unsigned char *data = NULL;
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);  
    // load and create a texture 
    // -------------------------
 //   unsigned int texture;
 //   glGenTextures(1, &texture);
 //   glBindTexture(GL_TEXTURE_2D, texture); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
 //   // set the texture wrapping parameters
 //   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
 //   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
 //   // set texture filtering parameters
 //   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
 //   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 //   // load image, create texture and generate mipmaps
 //   // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.

 //   capture_image( ( char ** ) &streamBuff, &size);
 //   std::cout << size << std::endl;
 //   unsigned char *data = NULL;
 //   data = stbi_load_from_memory( streamBuff, size, &width, &height, &nrChannels, 0);
 //   std::cout << width << " " << height << std::endl;
 //   if (data)
 //   {
 //       glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
 //       glGenerateMipmap(GL_TEXTURE_2D);
 //   }
 //   else
 //   {
 //       std::cout << "Failed to load texture" << std::endl;
 //   }
 //   stbi_image_free(data);
    // -----------------------------
    // --- Texture sharing start ---
    // -----------------------------

    // Socket paths for sending/receiving file descriptor and image storage data
    const char *SERVER_FILE = "/tmp/test_server";
    const char *CLIENT_FILE = "/tmp/test_client";
    // Custom image storage data description to transfer over socket
    struct texture_storage_metadata_t
    {
        int fourcc;
        EGLuint64KHR modifiers;
        EGLint stride;
        EGLint offset;
    };

    // GL texture that will be shared
    GLuint texture;

    // The next `if` block contains server code in the `true` branch and client code in the `false` branch. The `true` branch is always executed first and the `false` branch after it (in a different process). This is because the server loops at the end of the branch until it can send a message to the client and the client blocks at the start of the branch until it has a message to read. This way the whole `if` block from top to bottom represents the order of events as they happen.
#ifndef CLIENT
        // GL: Create and populate the texture
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, TEXTURE_DATA_WIDTH, TEXTURE_DATA_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
        capture_image( ( char ** ) &streamBuff, &size);
    std::cout << size << std::endl;
        data = stbi_load_from_memory( streamBuff, size, &width, &height, &nrChannels, 0);
        glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, TEXTURE_DATA_WIDTH, TEXTURE_DATA_HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        // EGL: Create EGL image from the GL texture
        EGLImage image = eglCreateImage(egl_display,
                                        egl_context,
                                        EGL_GL_TEXTURE_2D,
                                        (EGLClientBuffer)(uint64_t)texture,
                                        NULL);
       std::cout<<eglGetError()<<std::endl; 
        assert(image != EGL_NO_IMAGE);
        // The next line works around an issue in radeonsi driver (fixed in master at the time of writing). If you are
        // having problems with texture rendering until the first texture update you can uncomment this line
        // glFlush();

        // EGL (extension: EGL_MESA_image_dma_buf_export): Get file descriptor (texture_dmabuf_fd) for the EGL image and get its
        // storage data (texture_storage_metadata)
        int texture_dmabuf_fd;
        struct texture_storage_metadata_t texture_storage_metadata;

        int num_planes;
        PFNEGLEXPORTDMABUFIMAGEQUERYMESAPROC eglExportDMABUFImageQueryMESA =
            (PFNEGLEXPORTDMABUFIMAGEQUERYMESAPROC)eglGetProcAddress("eglExportDMABUFImageQueryMESA");
        EGLBoolean queried = eglExportDMABUFImageQueryMESA(egl_display,
                                                           image,
                                                           &texture_storage_metadata.fourcc,
                                                           &num_planes,
                                                           &texture_storage_metadata.modifiers);
        assert(queried);
        assert(num_planes == 1);
        PFNEGLEXPORTDMABUFIMAGEMESAPROC eglExportDMABUFImageMESA =
            (PFNEGLEXPORTDMABUFIMAGEMESAPROC)eglGetProcAddress("eglExportDMABUFImageMESA");
        EGLBoolean exported = eglExportDMABUFImageMESA(egl_display,
                                                       image,
                                                       &texture_dmabuf_fd,
                                                       &texture_storage_metadata.stride,
                                                       &texture_storage_metadata.offset);
        assert(exported);

        // Unix Domain Socket: Send file descriptor (texture_dmabuf_fd) and texture storage data (texture_storage_metadata)
        int sock = create_socket(SERVER_FILE);
        while (connect_socket(sock, CLIENT_FILE) != 0)
            ;
        write_fd(sock, texture_dmabuf_fd, &texture_storage_metadata, sizeof(texture_storage_metadata));
        close(sock);
        close(texture_dmabuf_fd);
#else
        // Unix Domain Socket: Receive file descriptor (texture_dmabuf_fd) and texture storage data (texture_storage_metadata)
        int texture_dmabuf_fd;
        struct texture_storage_metadata_t texture_storage_metadata;

        int sock = create_socket(CLIENT_FILE);
        read_fd(sock, &texture_dmabuf_fd, &texture_storage_metadata, sizeof(texture_storage_metadata));
        close(sock);

        // EGL (extension: EGL_EXT_image_dma_buf_import): Create EGL image from file descriptor (texture_dmabuf_fd) and storage
        // data (texture_storage_metadata)
        EGLAttrib const attribute_list[] = {
            EGL_WIDTH, TEXTURE_DATA_WIDTH,
            EGL_HEIGHT, TEXTURE_DATA_HEIGHT,
            EGL_LINUX_DRM_FOURCC_EXT, texture_storage_metadata.fourcc,
            EGL_DMA_BUF_PLANE0_FD_EXT, texture_dmabuf_fd,
            EGL_DMA_BUF_PLANE0_OFFSET_EXT, texture_storage_metadata.offset,
            EGL_DMA_BUF_PLANE0_PITCH_EXT, texture_storage_metadata.stride,
            EGL_DMA_BUF_PLANE0_MODIFIER_LO_EXT, (uint32_t)(texture_storage_metadata.modifiers & ((((uint64_t)1) << 33) - 1)),
            EGL_DMA_BUF_PLANE0_MODIFIER_HI_EXT, (uint32_t)((texture_storage_metadata.modifiers>>32) & ((((uint64_t)1) << 33) - 1)),
            EGL_NONE};
        EGLImage image = eglCreateImage(egl_display,
                                        NULL,
                                        EGL_LINUX_DMA_BUF_EXT,
                                        (EGLClientBuffer)NULL,
                                        attribute_list);
        assert(image != EGL_NO_IMAGE);
        close(texture_dmabuf_fd);

        // GLES (extension: GL_OES_EGL_image_external): Create GL texture from EGL image
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glEGLImageTargetTexture2DOES(GL_TEXTURE_2D, image);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
#endif
    // -----------------------------
    // --- Texture sharing end ---
    // -----------------------------

    // render loop
    // -----------
    while (!glfwWindowShouldClose(glfw_window))
    {
        // input
        // -----
        processInput(glfw_window);

        gl_draw_scene(texture );
        eglSwapBuffers( egl_display, egl_surface );
        // render
        // ------
//        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);

        // bind Texture
      //  glBindTexture(GL_TEXTURE_2D, texture);
        
  //  unsigned int texture;
   // glGenTextures(1, &texture);

#ifndef CLIENT
    glBindTexture(GL_TEXTURE_2D, texture); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    // set the texture wrapping parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
  //  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
  //  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
 //   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
      if( data != NULL) {
            stbi_image_free(data);
            data = NULL;
        }
        

        capture_image( ( char ** ) &streamBuff, &size);
        data = stbi_load_from_memory( streamBuff, size, &width, &height, &nrChannels, 0);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);


   //     glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    //    glClear(GL_COLOR_BUFFER_BIT);
     //   glBindTexture( GL_TEXTURE_2D, texture );
    std::cout<< "err: " << __LINE__ << " " << glGetError()<<std::endl;
        glTexSubImage2D( GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
    std::cout<< "err: " << __LINE__ << " " << glGetError()<<std::endl;


        //EGLImage image = eglCreateImage( )

        // render container
        ourShader.use();
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    std::cout<< "err: " << __LINE__ << " " << glGetError()<<std::endl;
        // -------------------------------------------------------------------------------
       // glfwSwapBuffers(glfw_window);
        glfwPollEvents();
        glBindTexture(GL_TEXTURE_2D, 0);
    std::cout<< "err: " << __LINE__ << " " << glGetError()<<std::endl;
#endif
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    if( texture )
        glDeleteTextures(1, &texture);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    exit_v4l2_lib_stream();
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *glfw_window)
{
    if (glfwGetKey(glfw_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(glfw_window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow*glfw_window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}