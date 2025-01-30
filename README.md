# Blood Glucose Level (BGL) Analysis Program

This program analyzes blood glucose levels (BGL) of patients, sorts data, provides risk analysis, and exports high-risk patient information.

- **Data Input**: Reads patient ID, name, blood type, and BGL values from a file.
- **Sorting Mechanism**: Sorts patients in descending order based on BGL values.
- **BGL Risk Analysis**: Categorizes patients with BGL >= 180 mg/dL as high-risk.
- **Data Export**: Saves high-risk patient details to a file.
- **Real-Time BGL Analysis**: Allows user input for immediate BGL evaluation.
- **Formatted Output**: Displays patient data in a structured table format.

## Example Usage
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

