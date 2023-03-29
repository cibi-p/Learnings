# Machine Learning

**Arthur samuel (1959). Machine Learning:** Field of study that gives computers the ability to learn without being explicitly programmed.

**Tom Mitchell (1998) Well-posed learning problem:** A computer program is said to learn form experience E with respect to some task T and some performance measure P, if its performance on T, as measured by P, improves with the experience E.

**ML Algorithms**
- Supervised Learning (output is available in the input dataset)
- Unsupervised Learning (output is not available in the dataset)

Others: Reinforcement Learning, Recommender Systems.

## Supervised Learning

If targe/output/label is available in the dataset

- **Regression:** If target is continuous/time dependent and whose target values are real (Ex: Housing Price Prediction)
- **Classification:** If target is discrete and classified in nature (ex: today we will have rain or not)

### Regression


#### Linear Regression
- Univariate Linear Regression (one input column and one output column)
- Multivariate Linear Regression (more than one input column and  one output column)

**univariate Linear Regression**

<mark>Formula for **straight line**\
*$h_\theta(x)=\theta_0 +\theta_1 x$*</mark>\
where **$\theta $** is the slope, formula is <mark>
$\theta_1=\frac{y2-y1}{x2-x1}$ </mark>(x1,x2,y1,y2 are the two points of the straight line) and **$\theta_0 $** is the intercept.

(in this below image theta and theta1 are represented interchaningly)
![linearregression](https://user-images.githubusercontent.com/57592824/227709109-9f901b6d-f61c-42bd-9e5c-f6d946c62db9.png)

---
Format:\
x --> input \ independent values \ features\
$h_\theta$ --> output \ dependent values \ target\
m --> number of records/training samples (row size)\
n --> number of features/columns (no. of x) (column size)\
($x^{(i)},y^{(i)}$) --> for the ith training sample (single record at the ith row)
<mark>  

**Error/cost function**\
Cost function is the summation of all the losses in your model.\
loss=(Actual value - Predicted Value)


![linearregression_error](https://user-images.githubusercontent.com/57592824/227709867-362c989e-352e-47a4-919f-3f188745ffce.png)

- Cost Function = $\sum_{i=1}^m (Actual value - Predicted value)$\
where m is the number of records

- Cost Function,<mark> 
J($\theta_0,\theta_1$)= $\frac{1}{2m} \sum_{i=1}^m (h_\theta(x^{(i)})-y^{(i)})^2$</mark> (this is known as **Mean Square Error (MSE)**) (Square is used to avoid negative number)

- where m is the number of records, $h_\theta(x^{(i)})$ is the Predicted Value of the ith record, $y^{(i)}$ is the Actual Value of the ith record (we already know)

- Our goal is to minimize the J($\theta_0,\theta_1$) value.

**considering only slope**
- We know that the intercept $\theta_0$ is constant, so for simplicity we can not consider it.
- Equation becomes *$h_\theta(x)=\theta_1 x$*
- Cost function Becomes J($\theta_1$)= $\frac{1}{2m} \sum_{i=1}^m (h_\theta(x^{(i)})-y^{(i)})^2$
- Here our goal is to minimize J($\theta_1$)

![Costfunction](https://user-images.githubusercontent.com/57592824/227752325-56e70ce3-49ce-43a6-936b-007527f76f48.png)

**Gradient Descent ALgorithm**
1. Need to initialize parameters($\theta_0, \theta_1$) by any value.
1. Provide number of iteration(1000)

Explanation:

Gradient Descent Algorithm iteratively calculates the next point using gradient at the current position, scales it (by a learning rate) and subtracts obtained value from the current position (makes a step). It subtracts the value because we want to minimise the function (to maximise it would be adding). This process can be written as:

$p_{n+1}=p_n-\eta \nabla f(p_n)$

There’s an important parameter $\eta$ which scales the gradient and thus controls the step size. In machine learning, it is called learning rate and have a strong influence on performance.

- The smaller learning rate the longer GD converges, or may reach maximum iteration before reaching the optimum point
- If learning rate is too big the algorithm may not converge to the optimal point (jump around) or even to diverge completely.

In summary, Gradient Descent method’s steps are:
1. choose a starting point (initialisation)
2. calculate gradient at this point
3. make a scaled step in the opposite direction to the gradient (objective: minimise)
4. repeat points 2 and 3 until one of the criteria is met:
- maximum number of iterations reached
- step size is smaller than the tolerance (due to scaling or a small gradient).
Link: [Gradient Descent Algorithm](https://towardsdatascience.com/gradient-descent-algorithm-a-deep-dive-cf04e8115f21), [other Link](https://www.analyticsvidhya.com/blog/2020/10/how-does-the-gradient-descent-algorithm-work-in-machine-learning/)

![image](https://user-images.githubusercontent.com/57592824/227755386-1e9e7f06-4f24-4211-8857-8727a10c8c5c.png)

we know that J($\theta_0,\theta_1$)= $\frac{1}{2m} \sum_{i=1}^m (h_\theta(x^{(i)})-y^{(i)})^2$, if we substitude and take differentiate we get this, we also know $h_\theta(x)=\theta_0 x+\theta_1$

![image](https://user-images.githubusercontent.com/57592824/227755525-d6edbe6f-da14-42b6-a47c-751fab493fbf.png)

![image](https://user-images.githubusercontent.com/57592824/227755281-45a8c243-9926-4dd5-aec4-477eed32c6d3.png)

Note:\
Over fitting error: If the model produce less error for training dataset and more error on testing dataset. To solve this using Regularization.


**Feature Scaling**

It makes the values in the scale of decimal of 0 and 1 on the individual column, to give the equalization to all the column. ex values: 0.2342,0.3434m,1.975,1.0654...

**Multivariate Linear Regression**

*$h_\theta(x)=\theta +\theta_1 X_1 +\theta_2 X_2+...$*</mark> Based on the number of features or columns

also need to find $\theta_0, \theta_1, \theta_2...$ in the Gradient Descent algorithm

**Steps**
1. Identify whether it is a Supervised learning or not and Regression ot not
1. Plot the scatter plot, If you found the linear relation ship then use the linear regression
1. Find the Hypothesis or model representation
1. Find the Cost Function 
2. Gradient descent algorithm
1. Feature Scaling
1. splitting Training and testing data
1. building the model
1. Find the metrics like Mean Square Error, Precision, acuracy, recall and f1_score

Jupyter notebook link: [Linear regression]()


### Classification
Output is in Discrete Value
**Logistic Regression**
It is like giving thershold to the Linear Regression using the sigmoid function

Sigmoid function=$\frac{1}{1+e^{-z}}$, if we put z=-$\infty$ and $\infty$. we get sigmoid function output as 0 and 1. so it convert the all the values between the 0 and 1.

![image](https://user-images.githubusercontent.com/57592824/227759466-bdcdbbc4-a73d-4d33-94a9-0064ff827c62.png)


Hypothesys function become\
<mark>
$h_\theta(x)=\frac{1}{1+e^{-\theta^Tx}}$
</mark>, here $\theta^Tx$ is the Linear regression model. T represent the transpose

![Logistic regression](https://user-images.githubusercontent.com/57592824/227759823-5d63c949-81fd-4fa8-abab-b8fcd43447a2.png)

After the values is bound between the 0 and 1, it is applied on the threshold value to produce the discrete output

**Cost function**
if we plot directly the graph of the the Logistic cost function, it will be like this

![COstfunction_logistic_regression](https://user-images.githubusercontent.com/57592824/227760283-397cebed-f70b-44b6-9164-67d3782662ca.png)

to avoid this we are going to use log() function to cancel the effect of the exponential. so it will increase the efficiency

Cost function:
- $J(\theta) = \frac{1}{m} \sum^m_{i=1}cost(h_\theta(x^{(i)}),y^{(i)})$
- $cost(h_\theta(x),y)= -log(h_\theta(x))$ if y=1 , it tell the cost value for 1
- $cost(h_\theta(x),y)= -log(1-h_\theta(x))$ if y=0 , it tell the cost value for 0

![GDLogisticregression](https://user-images.githubusercontent.com/57592824/227850562-e995bf3c-6b86-4353-8097-c97243d729df.png)

Link for Logistic regression Jupyter notebook

### Naive Bayes

## Unsupervised Learning
- Output is not given in the dataset.
- It creates the cluster of the common pattern

### K-means Clustering algorithm

1. initializing the n number of cluster, coefficient for the n cluster's