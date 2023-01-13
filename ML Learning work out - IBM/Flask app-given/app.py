from flask import Flask, render_template, request

app = Flask(__name__)


# interface between my server and my application wsgi
import pickle
model = pickle.load(open('model.pkl','rb'))

@app.route('/')#binds to an url
def helloworld():
    return render_template("index.html")

@app.route('/login', methods =['POST'])#binds to an url
def login():
    p =request.form["ms"]
    q= request.form["as"]
    r= request.form["rd"]
    s= request.form["s"]
    if (s=="cal"):
        s1,s2,s3=1,0,0
    if (s=="flo"):
        s1,s2,s3=0,1,0
    if (s=="ny"):
        s1,s2,s3=0,0,1
    t=[[int(s1),int(s2),int(s3),int(p),int(q),int(r)]]
    output= model.predict(t)
    print(output)  
        
    return render_template("index.html",y = "the predicted profit is  " + str(output[0][0]))  #we can only concatenate string to str

@app.route('/admin')#binds to an url
def admin():
    return "Hey Admin How are you?"

if __name__ == '__main__' :
    app.run(debug= False)
    
