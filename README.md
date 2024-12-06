# HospitalManagementSystem
Simple hospital management system for registering patient and displaying patient's data.

- The file name being used to store patient and doctor data are customizable. Simply change the file name inside the clinicalRecord.LoadFromFile("yourpatientdatahere.txt"); function in mainprogram.cpp file to load patient data. For doctor data, change the file name under  void LoadDoctorData() {ifstream file("yourdoctordatahere.txt");} function in register.hpp file.

- Since the program uses the read-by-space method to read the .txt file, for now, multi-spaced data input like in name or complain, need to use dash lines (-) so the program could read correctly through it

