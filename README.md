# Blood Glucose Level (BGL) Analysis

This C project is designed to help track patient health and identify those at risk of complications from high BGL. The way it works is by reading patient data, including ID, name, blood type, and BGL values from a file. It then sorts the patients based on their BGL levels in descending order. The program categorizes patients with a BGL greater than or equal to 180 mg/dL as high-risk and exports their details to a file for further monitoring. You can also input a BGL value manually to assess the current status, with the program providing real-time feedback on whether the patient is at risk of hyperglycemia.

I created this project to combine data analysis with health management. I was inspired by the idea of using data to help manage and predict health risks. By sorting patients and providing immediate analysis, I wanted to give healthcare professionals a useful tool for monitoring patient conditions and taking action quickly.

## Example Output
```
Patient ID   Name      Blood Type       BGL
345678       Charlie         B         210
123456       Alice           O         190
234567       Bob             A         145

Number of patients having BGL >= 180 mg per dL: 2
Number of patients having BGL < 180 mg per dL: 1

High-risk patients exported to 'high_risk_patients.txt'.

Enter a blood glucose level for analysis: 200
High blood sugar (hyperglycemia). Monitor closely.

```

