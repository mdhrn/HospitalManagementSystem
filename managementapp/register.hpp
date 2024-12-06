#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

    int PatientID ;
    string PatientName ;
    string PatientSex ;
    string PatientPhone ;
    string PatientBloodType ;
    int PatientAge ;
    string PatientComplain ;
   

    string DoctorKeyAccess = "1234" ;

class Patient_Data {
    public:
    int PatientID ;
    string PatientName ;
    string PatientSex ;
    string PatientPhone ;
    string PatientBloodType ;
    int PatientAge ;
    string PatientComplain ;
    
    
     Patient_Data()
        : PatientID(0), PatientAge(0) {} // Initialize integers to 0

    public:
    //get patient's information
    void RegisterInformation() {
        cout << "------------ Patient Registration------------ \n";

        cout << "ID number      : ";
        cin >> PatientID;
        cin.ignore();

        cout << "Name           : ";
        getline(cin, PatientName);

        cout << "Sex            : ";
        getline(cin, PatientSex);

        cout << "Age            : ";
        cin >> PatientAge;
        cin.ignore();

        cout << "Phone number   : ";
        getline(cin, PatientPhone);

        cout << "Blood Type     : ";
        getline(cin, PatientBloodType);

        cout << "Complain       : ";
        getline (cin, PatientComplain);

    } 
// Save patient data to a specific file
void PatientsaveToFile(const string& filename) const {
    ofstream file(filename, ios::app); // Open file in append mode
    if (!file) {
        cout << "Error: Could not open file for saving patient data.\n";
        return;
    }

    file << PatientID << " " << PatientName << " " << PatientSex << " " << PatientAge << " "
         << PatientPhone << " " << PatientBloodType << " " << PatientComplain << " "
         << endl;

    file.close(); // Close the file after saving
}


    
} ;

class Doctor_Data {
    public:
    string DoctorName;
    int DoctorID;
    string DoctorSpecialty;
    vector<Doctor_Data> DoctorList;

 void LoadDoctorData() {
    ifstream file("doctordata.txt");
    if (!file) {
        cout << "No data can be read" << endl;
        return;
    }

    DoctorList.clear(); // Clear the vector to avoid duplicates

    while (file >> DoctorID >> DoctorName >> DoctorSpecialty) {
       
        Doctor_Data doctor;
        doctor.DoctorID = DoctorID;
        doctor.DoctorName = DoctorName;
        doctor.DoctorSpecialty = DoctorSpecialty;

        // Add the new doctor to the DoctorList vector
        DoctorList.push_back(doctor);

            cout << "Doctor ID        : " << DoctorID << " \n";           
            cout << "Doctor Name      : " << DoctorName << "\n ";
            cout << "Doctor Specialty :" << DoctorSpecialty << "\n " ; 
            cout << "======================" << "\n";
} 

file.close();
   }
 


    Doctor_Data* FindDoctorID(int id) {
        for (auto& doctor : DoctorList) {
            if (doctor.DoctorID == id) {
                return &doctor; // Return pointer to matching doctor
            }
        }
        return nullptr; // Return nullptr if not found
    }
};


class Access_Control {
    public:
 //method to access pages
    
    string DoctorKeyAccess = "1234" ;
    
    
bool VerifyRole (string position){
    string InputKey;

    cout << "Input Key Access :" << "\n";
    cin >> InputKey;

    if (position == "Doctor" && InputKey == DoctorKeyAccess ){
        cout << "Access granted, welcome Doctor! " << "\n";
        return true;
    }

    else {

        cout << "Invalid role" << endl;
        return false ; 
    }

    
}
    
};


class Clinical_Record {
    public:
    vector<Patient_Data> PatientsRecord; // Define a vector to hold Patient_Data objects

    void LoadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: Could not open file for reading patient data.\n";
        return;
    }

    PatientsRecord.clear(); // Clear any existing data in the vector

    Patient_Data patient; // Temporary object for storing data from file

    while (file >> patient.PatientID 
                >> patient.PatientName 
                >> patient.PatientSex 
                >> patient.PatientAge 
                >> patient.PatientPhone 
                >> patient.PatientBloodType 
                >> patient.PatientComplain) {
        PatientsRecord.push_back(patient); // Add the patient object to the vector
    }

    if (PatientsRecord.empty()) {
        cout << "No valid patient records were loaded.\n";
    } else {
        cout << "Successfully loaded " << PatientsRecord.size() << " patient records from the file.\n";
    }
}


    //Method to display all patient data
    void DisplayPatient_Data() const {
        if (PatientsRecord.empty()) { // Check if there are no records
            cout << "No patient records available.\n";
            return;
        }

        // Iterate through the vector and display each patient's data
        for (size_t i = 0; i < PatientsRecord.size(); ++i) {
            cout << "Patient ID         : " << PatientsRecord[i].PatientID << "\n";
            cout << "Patient Name       : " << PatientsRecord[i].PatientName << "\n";
            cout << "Sex                : " << PatientsRecord[i].PatientSex << "\n";
            cout << "Patient Age        : " << PatientsRecord[i].PatientAge << "\n";
            cout << "Phone Number       : " << PatientsRecord[i].PatientPhone << "\n";
            cout << "Patient Blood Type : " << PatientsRecord[i].PatientBloodType << "\n";
            cout << "Patient Complain   : " << PatientsRecord[i].PatientComplain << "\n";
            cout << "======================\n";

            
        }
    }

    //Method to add a new patient to the record
    void AddPatient(const Patient_Data& patient) {
        PatientsRecord.push_back(patient);
        cout << "Patient added successfully!\n";
    }


};



class Appointment_Schedule {
    public:
    int AppointmentID;
    Doctor_Data doctorData;
    string AppointmentDate;  //DD-MM-YY
    string AppointmentTime; 
    string SelectedDoctorID;
    int AppointmentTimeChoice;
    string DoctorChoice;


    void ScheduleAppointment (const Patient_Data& patient){

        cout << "-----------" << "SCHEDULING APPOINTMENT " << "-----------" << "\n";
        cout << right << " Enter Appointment Date (DD / MM / YY) :" << left << "\n";
        cin >> AppointmentDate ;

        cout << "Select Appointment Session : \n";

        cout << " 1. (08.00 - 09.00) \n ";
        cout << " 2. (11.00 - 12.00) \n" ;
        cout << " 3. (12.00 - 13.00) \n ";
        cout << " 4. (13.00 - 14.00) \n" ;

        cin >> AppointmentTimeChoice;
            if (AppointmentTimeChoice == 1){
                AppointmentTime = " 1. (08.00 - 09.00) \n ";
                
            }

            else if (AppointmentTimeChoice == 2){
                AppointmentTime = "2. (11.00 - 12.00) \n";
                

            }
            
            else if (AppointmentTimeChoice == 3){
                AppointmentTime = "3. (12.00 - 13.00) \n";
                

            }

            else if (AppointmentTimeChoice == 4){
                AppointmentTime = "4. (13.00 - 14.00) \n";
                
            }

            else {
                cout << "Invalid session, choose another session " << endl;
            
            }


        cout << setw(40) << "DOCTOR AVAIBLE : " << setw(40) << "\n";
        
        doctorData.LoadDoctorData();

        cout << "Enter Doctor ID : \n" ;

        cin >> SelectedDoctorID;

        cout << " " << endl;
   

         int doctorID = stoi(SelectedDoctorID); // Convert input to integer

        Doctor_Data* selectedDoctor = doctorData.FindDoctorID(doctorID);

        if (selectedDoctor) {
            DoctorChoice = selectedDoctor->DoctorName;
        } else {
            cout << "Invalid Doctor ID. Please try again." << endl;
            return; // Exit function if doctor not found
        }



        cout << "------------" << " APPPOINTMENT SCHEDULED " <<  "------------" <<  "\n";
        cout << " Name             : " << patient.PatientName << "\n";
        cout << " Patient ID       : " << patient.PatientID << "\n";
        cout << " Appointment Time : " << AppointmentTime << "\n";
        cout << " Doctor           : " << selectedDoctor->DoctorName << "\n";
    
    }
    };

