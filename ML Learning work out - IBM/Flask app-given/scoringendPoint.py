import requests

# NOTE: you must manually set API_KEY below using information retrieved from your IBM Cloud account.
API_KEY = "oiXUdbwKFqHbkZTR6ZHXgLl5DWH3_p0i9knkXNeVhgeP"
token_response = requests.post('https://iam.cloud.ibm.com/identity/token', data={"apikey":
 API_KEY, "grant_type": 'urn:ibm:params:oauth:grant-type:apikey'})
mltoken = token_response.json()["access_token"]

header = {'Content-Type': 'application/json', 'Authorization': 'Bearer ' + mltoken}

# NOTE: manually define and pass the array(s) of values to be scored in the next line
payload_scoring = {"input_data": [{"fields": [["f0","f1","f2","f3","f4","f5"]], "values":[[0,0,1,12345,23453,34567]] }]}

response_scoring = requests.post('https://us-south.ml.cloud.ibm.com/ml/v4/deployments/08bac2cf-1f16-4f7a-a47f-eff02351dab0/predictions?version=2022-05-30', json=payload_scoring,
 headers={'Authorization': 'Bearer ' + mltoken})
print("Scoring response")
#print(response_scoring.json())
pred= response_scoring.json()
output=pred['predictions'][0]['values'][0][0][0]
print(output)
