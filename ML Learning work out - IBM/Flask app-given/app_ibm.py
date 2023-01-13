from flask import Flask, render_template, request

import requests

# NOTE: you must manually set API_KEY below using information retrieved from your IBM Cloud account.
API_KEY = "3HCuzUMTmb81LGVaUesD2TFsQGK1WlbEtfsGzteMzn-K"
token_response = requests.post('https://iam.cloud.ibm.com/identity/token', data={"apikey":
 API_KEY, "grant_type": 'urn:ibm:params:oauth:grant-type:apikey'})
mltoken = token_response.json()["access_token"]

header = {'Content-Type': 'application/json', 'Authorization': 'Bearer ' + mltoken}

app = Flask(__name__)# interface between my server and my application wsgi


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
    #output= model.predict(t)
    #print(output)  
    # NOTE: manually define and pass the array(s) of values to be scored in the next line
    payload_scoring = {"input_data": [{"fields": [['f0','f1','f2','f3','f4','f5']], "values":t}]}
    
    response_scoring = requests.post('https://us-south.ml.cloud.ibm.com/ml/v4/deployments/046ce4b6-305e-4da2-a27a-c0e7a964b2fd/predictions?version=2022-10-12', json=payload_scoring,
     headers={'Authorization': 'Bearer ' + mltoken})
    print("Scoring response")
    pred=response_scoring.json()
    output=pred['predictions'][0]['values'][0]
    print(output)
        
    return render_template("index.html",y = "the predicted profit is  " + str(output) )

@app.route('/admin')#binds to an url
def admin():
    return "Hey Admin How are you?"

if __name__ == '__main__' :
    app.run(debug= False)
    
