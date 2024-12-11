
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
        cout << "\n--------------- Doctor Access ---------------\n";

        // Verify role
        if (accessControl.VerifyRole("Doctor")) {
            cout << "Identity verified, welcome Doctor.\n";
        } else {
            cout << "Access denied.\n";
            break; // Exit the case if access is denied
        }

        // Prompt for access to patient data
        int doctorAnswer;
        cout << "Do you want to see patient's data? [1 for Y/0 for N]: ";
        cin >> doctorAnswer;
        cout << endl;

        // Handle user response
        if (doctorAnswer == 1) {
            // Load and display patient data
            clinicalRecord.LoadFromFile("patientdata.txt");
            clinicalRecord.DisplayPatient_Data();
        } else if (doctorAnswer == 0) {
            cout << "Thank you, Doctor.\n";
        } else {
            cout << "Invalid input. Returning to the menu.\n";
        }

        break; // Exit the case
    }

    default: {
        cout << "Invalid choice! Please try again.\n";
        break; // Ensure default case ends properly
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


    }

    return 0;
}
