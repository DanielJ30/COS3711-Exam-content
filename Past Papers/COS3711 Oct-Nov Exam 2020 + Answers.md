# October-November 2020

---
**Disclaimer**:
These resources are meant for learning purposes and comes with no guarantee of accuracy or correctness.
Please do your own research and use it as a tool to double-check your own work, attempts and understanding.

---

## Case:
The questions in this paper are based on a simplified scenario where records of patients
admitted to a hospital with infections are kept.

A main client would be responsible for gathering all the required information from the user,
where the recording is based on a central container or list of patient records, which is written to
file when the application is closed and read in from file when the application is started. Patients
(who have a patient number) are considered to be of two types: health workers (where it needs
to be known where the patient works) and non-health worker patients (in which case the testing
site needs to be known).

Each patient record also has an object indicating the infection that the patient has (assuming
that each patient has only one infection). An infection (which has an infection code) could be
viral (with a flag indicating whether there is an antiviral that is effective against it) or bacterial
(with an indication of an antibiotic which is effective against it).

## Question 1
### Question 1.1:
Create a UML class diagram to express the scenario described above, taking design
patterns into consideration in the design.
You should include the necessary classes, class attributes, class operations, and class
relationships to make it clear you understand how data will be managed and passed
between classes. Include the Client class to be used. (20)

![Oct-Nov-2020 Q1.1.jpg](..%2FResources%2FOct-Nov-2020%20Q1.1.jpg)

