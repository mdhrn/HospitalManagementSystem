
#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
#include "register.hpp" // Include the header file containing class definitions

using namespace std;

int main() {

    int choice;
    Access_Control accessControl;                     // Access control for role verification
    Patient_Data patient;                            // Create a Patient_Data object
    Clinical_Record clinicalRecord;                  // Create a Clinical_Record object
    Appointment_Schedule appointmentSchedule;       // 
    vector <Patient_Data> PatientsRecord;
    
    cout << "\n===== HOSPITAL MANAGEMENT SYSTEM =====\n" << endl;
    cout << "Welcome to the system\n";
    cout << "Log in as:\n";
    cout << "1. Doctor\n";
    cout << "2. Patient\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    // Validate user input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Exiting the system.\n";
        return 0;
    }

    switch (choice) {
        case 1: { // Doctor Access
            cout << "\n--------------- Doctor Access---------------\n";
            if (accessControl.VerifyRole("Doctor")) {
                cout << "Identity verified, welcome Doctor.\n";
                
            } else {
                cout << "Access denied.\n";
            }

            int doctorAnswer;
            cout << "Do you want to see patient's data?";
            cout << "[1 for Y/0 for N]:";
            cin >> doctorAnswer;
            cout << endl;

            if (doctorAnswer == 1){
                clinicalRecord.LoadFromFile("patientdata.txt");

            // Call the function to display the file contents
             clinicalRecord.DisplayPatient_Data();

            break;


              
             
            }
            else if (doctorAnswer == 0){
                cout << "Thankyou, Doctor.";
            }
            else{
                cin.ignore();
            }


            break;
           


        }

        case 2: { // Patient Access
            cout << "\n--------------- Patient Access---------------\n";
            cout << "Welcome!\n";

            // Create an instance of the Patient_Data class
            Patient_Data patient;
            Appointment_Schedule appointmentSchedule;

            // Register the patient and save their information
            patient.RegisterInformation();
            
            // Save patient data to the file
            ofstream file("patientdata.txt", ios::app); // Open file in append mode
            if (file.is_open()) {
                patient.PatientsaveToFile("patientdata.txt");
                cout << "Patient data saved successfully.\n";
            } else {
                cout << "Error: Could not open file to save patient data.\n";
            }

            file.close();

            //Scheduling appointment
            appointmentSchedule.ScheduleAppointment(patient);

            break;
        }


        case 3: { // Exit
            cout << "Exiting the system. Goodbye!\n";
            break;
        }

        default: { // Invalid input
            cout << "Invalid choice, please select a valid option.\n";
            break;
        }
    }

    return 0;
}
