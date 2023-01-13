from flask import Flask, render_template, request
app=Flask(__name__)

import pickle
model=pickle.load(open('model.pkl','rb'))

@app.route('/')
def start():
    return render_template("index.html")

@app.route('/login', methods=['POST'])
def result():
    m_s=request.form["ms"]
    a_s=request.form["as"]
    r_d=request.form["rd"]
    state=request.form["s"]
    if (state=="cal"):
        s1,s2,s3=1,0,0
    if (state=="flo"):
        s1,s2,s3=0,1,0
    if (state=="ny"):
        s1,s2,s3=0,0,1
    t=[[int(s1),int(s2),int(s3),int(m_s),int(a_s),int(r_d)]]
    output=model.predict(t)
    print(output)
    
    return render_template("index.html",y="The Predicted profit is "+str(output))

@app.route('/admin')
def admin():
    return "Admin page"

if __name__ == '__main__':
    app.run(debug=False)