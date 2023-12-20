#include <iostream>
#include <string>
#include <fstream> 
#include <ctype.h>
#include <iomanip>
#include <cctype>
using namespace std;



struct discipline // Инициализация на помощна структура за име на дисциплина и оценка
{
	string name;
	int grade;
};


struct student_info { // инициализация на главна структура
	bool active;
	string faculty_number;
	string personal_id_number;
	string full_name;
	string gender;
	int age;
	string status_of_student;
	double sreden_uspeh;
	discipline disciplines[5] = { // променлива тип дисциплина

		 {"Basis of programming", 0},
		 {"Maths", 0},
		 {"Web Design", 0},
		 {"Electronics", 0},
		 {"Sport", 0}
	};
};

int return_num_students(student_info studentInfo[30]) { // връща броя на студенти въведени досега в масива
	int x = 0; // инициализация
	for (int i = 0;i < 30;i++) { // цикъл чрез който минаваме чрез масива
		if (studentInfo[i].active != true) { // бройм колко за колко студенти има информация
			x = i; 
			break; //ако стигнем до студент който не е инициализаиран връщаме броя на студенти досега и излизаме от цикъла
		}

	}
	return x; // връщаме броя на активни студенти
}
string convertToLowerCase(const string& str) {
	string result = str;

	// Convert each character to lowercase
	for (char& c : result) {
		c = tolower(c);
	}

	return result;
}
int calculate_average_grade(student_info student[30]) { // при повикване смята среден успех на всички досега въведени студенти
	int actual_number_of_students = return_num_students(student);
	for (int i = 0; i < actual_number_of_students;i++) {
		student[i].sreden_uspeh = (student[i].disciplines[0].grade + student[i].disciplines[1].grade + student[i].disciplines[2].grade + student[i].disciplines[3].grade + student[i].disciplines[4].grade) / 5.00;

	}
	return 0;

}

int input(student_info studentInfo[30]) // функция за въвеждане на студенти като в началото се пита колко студенти се иска да бъдат въведени в масива
{
	int number_of_students;
	cout << "Enter number of students you would like to add \n";
	cin >> number_of_students;
	while (number_of_students > 30 || number_of_students < 1) {
		cout << "Error: Number of students either over 30 or less than 1";
		cout << "Enter valid number of student" << endl;
		cin >> number_of_students;
	}

	int current_number_of_students = return_num_students(studentInfo);
	cout << "The current number of students is - " << current_number_of_students << endl;

	if (current_number_of_students + number_of_students < 30) {
		for (int i = 0; i < number_of_students; i++)
		{
			int student_number = current_number_of_students;
			studentInfo[student_number].active = true;
			cout << "Enter faculty number\n";
			cin >> studentInfo[student_number].faculty_number;
			cout << "Enter personal ID number\n";
			cin >> studentInfo[student_number].personal_id_number;
			cout << "Enter full name\n";
			cin.ignore(1000, '\n');
			getline(cin, studentInfo[student_number].full_name);

			for (int z = 0; z < 5;z++) {
				cout << "Enter grade for - " << studentInfo[student_number].disciplines[z].name << endl;
				cin >> studentInfo[student_number].disciplines[z].grade;
				while (studentInfo[student_number].disciplines[z].grade < 0 || studentInfo[student_number].disciplines[z].grade == 1 || studentInfo[student_number].disciplines[z].grade > 6) {
					cout << "Wrong input for grade.Try again\n";
					cin >> studentInfo[student_number].disciplines[z].grade;
				}
			}

			cout << "Enter gender of student\n";
			cin >> studentInfo[student_number].gender;
			studentInfo[student_number].gender = convertToLowerCase(studentInfo[student_number].gender);
			while (studentInfo[student_number].gender != "male" && studentInfo[student_number].gender != "female") {
				cout << "Invalid gender. Gender must either be male or female" << endl;
				cout << "Enter valid gender" << endl;
				cin >> studentInfo[student_number].gender;
			}
			cout << "Enter age of student\n";
			cin >> studentInfo[student_number].age;
			cout << "Enter status of student\n";
			cin >> studentInfo[student_number].status_of_student;
			studentInfo[student_number].status_of_student = convertToLowerCase(studentInfo[student_number].status_of_student);
			while (studentInfo[student_number].status_of_student != "active" && studentInfo[student_number].status_of_student != "dropout" && studentInfo[student_number].status_of_student != "graduated") {
				cout << "Invalid status for student. Valid statuses are active, dropout and graduated" << endl;
				cout << "Enter valid status for student" << endl;
				cin >> studentInfo[student_number].status_of_student;
				studentInfo[student_number].status_of_student = convertToLowerCase(studentInfo[student_number].status_of_student);
			}
		}
	}
	else {
		cout << "Cannot add that many students to database as it exceeds the limit of 30" << endl;
	}
	return 0;
}

	

int output(student_info studentInfo[30]) // функция която извежда досега въведените студенти

{
	if (return_num_students(studentInfo) > 0) {
		int current_number_of_students = return_num_students(studentInfo);

		cout << "The current number of students is - " << current_number_of_students << endl;
		cout << "*********-Table of students-*****************\n";

		cout << setw(5) << "Index" << setw(15) << "Faculty No" << setw(20) << "Personal ID" << setw(25) << "Full Name" // задаваме дължина на полето
			<< setw(15) << "Gender" << setw(5) << "Age" << setw(20) << "Status" << endl;

		for (int i = 0; i < current_number_of_students; i++)
		{
			cout << setw(5) << i << setw(15) << studentInfo[i].faculty_number << setw(20) << studentInfo[i].personal_id_number
				<< setw(25) << studentInfo[i].full_name << setw(15) << studentInfo[i].gender << setw(5) << studentInfo[i].age
				<< setw(20) << studentInfo[i].status_of_student << endl;

			for (int z = 0; z < 5; z++)
			{
				cout << setw(30) << studentInfo[i].disciplines[z].name << " grade -  " << studentInfo[i].disciplines[z].grade << endl;
			}

			cout << "-------------------------------------------\n";
		}

		cout << "*************-End of Table*****************\n";
	}
	else {
		cout << "No information for students filled in yet. Enter information first" << endl;
	}
	return 0;
}

int search_in_range_or_look_for_fail(student_info student[30]) // функция с подменю: опция едно търси студенти с оценки по БП в интервал а опция две търси студенти с оценка 2 по която и да е дисциплина
{
	int option1;
	bool flag = false;
	cout << "Enter option 1 to look for students with BP grades in a range. Enter option 2 to look for fail grades\n";
	cin >> option1;
	if (option1 == 1) {
		int lower_interval, higher_interval;
		cout << "Enter lower range for BP grade" << endl;
		cin >> lower_interval;
		while (lower_interval < 2) {
			cout << "Error lower interval for grades cannot be lower than 2" << endl;
			cin >> lower_interval;
		}

		cout << "Enter higher for BP grade" << endl;
		cin >> higher_interval;
		while (higher_interval > 6) {
			cout << "Error higher interval cannot be higher than 6" << endl;
		}
		for (int i = 0; i < return_num_students(student); i++)
		{
			if (student[i].disciplines[0].grade >= lower_interval && student[i].disciplines[0].grade <= higher_interval) {
				cout << student[i].full_name << endl;
			}

		}

	}
	else if (option1 == 2) {
		for (int z = 0; z < return_num_students(student);z++){
			for(int x = 0; x < 5; x++){
				if (student[z].disciplines[x].grade == 2) {
					cout << student[z].full_name << endl;
					flag = true;
					break;

				}
				
			}
	
		}
		if (!flag) { // ако няма оценки 2 
			cout << "No students with grade 2" << endl;
		}
	
	}
	
	else { // при грешна опция
		cout << "Wrong input for option. Enter 1 or 2\n";
		cin >> option1;
	}




	return 0;
}
int swap(student_info& a, student_info& b) // помощна функция за размяната местата на два елемента в масивц
{
	student_info temp = a;
	a = b;
	b = temp;
	return 0;
}



int sort_by_firstname(student_info student[30]) // сортиране на 
{
	int n = return_num_students(student);
	for (int i = 0; i < n - 1;i++) {
		for (int j = 0; j < n - i - 1;j++) {
			string student_first_name = student[j].full_name.substr(0, student[j].full_name.find(' '));
			string student_first_name_plus_one = student[j + 1].full_name.substr(0, student[j + 1].full_name.find(' '));
			if (student_first_name > student_first_name_plus_one) {
				swap(student[j], student[j + 1]);
			}
		}
	}
	cout << "Sorted Students by First Name:\n";
	for (int i = 0; i < n; i++) {
		cout << student[i].full_name << endl;;
	}


	return 0;
}
int write_to_file(student_info student[30]) {
	ofstream ofs;
	ofs.open("test.txt", ios::app);
	if (ofs.is_open())
	{
		
		for (int i = 0; i < return_num_students(student);i++) {
			
			ofs << student[i].faculty_number << endl;
			ofs << student[i].personal_id_number << endl;
			ofs << student[i].full_name << endl;
			for (int z = 0; z < 5; z++) {
				ofs << student[i].disciplines[z].grade << endl;

			}
			ofs << student[i].gender << endl;
			ofs << student[i].age << endl;
			ofs << student[i].status_of_student << endl;
			
			

		}
		
		
	}
	ofs.close();
	cout << "Output operation successfully performed\n";
	return 0;
}
int read_array_from_file(student_info student[30]) {
	ifstream ifs("file_with_info.txt");
	int i = 0;
	int current_number_of_stud = return_num_students(student);
	cout << "Current number of students: " << current_number_of_stud << endl;

	if (ifs.is_open()) {
		while (i < 30 && ifs >> student[i].faculty_number) {
			ifs >> student[i].personal_id_number;
			getline(ifs >> ws, student[i].full_name);

			for (int z = 0; z < 5; z++) {
				ifs >> student[i].disciplines[z].grade;
			}

			ifs >> student[i].gender;
			ifs >> student[i].age;
			ifs >> student[i].status_of_student;
			student[i].status_of_student = convertToLowerCase(student[i].status_of_student);

			student[i].active = true;
			i++;
		}

		cout << "Data read successfully from the file." << endl;
	}
	else {
		cout << "Error opening the file." << endl;
	}

	ifs.close();
	return i;  // Return the number of students read from the file
}




int seperate_students_by_status(student_info student[30]) {
	string status_warranted;
	int count = 0;
	bool flag = false;
	bool flag2 = false;
	if (return_num_students(student) > 0) {
		flag2 = true;
		cout << "Enter status you would like to filter by\n";
		cout << "Valid statuses are active,dropout and graduated" << endl;
		cin >> status_warranted;
		while (status_warranted != "active" && status_warranted != "dropout" && status_warranted != "graduated") {
			cout << "Error: Invalid status. Status must be active, dropout or graduated" << endl;
			cin >> status_warranted;
		}
		status_warranted = convertToLowerCase(status_warranted);
		int filtered_pid[30];

		for (int i = 0; i < return_num_students(student); i++) {
			if (student[i].status_of_student == status_warranted) {
				filtered_pid[count] = i;
				count++;
				flag = true;
			}

		}
		for (int i = 0; i < count - 1;i++) {
			for (int j = 0; j < count - i - 1;j++) {
				if (filtered_pid[j] > filtered_pid[j + 1]) {
					int temp = filtered_pid[j];
					filtered_pid[j] = filtered_pid[j + 1];
					filtered_pid[j + 1] = temp;
				}
			}
		}
		if(flag){
			cout << "Faculty numbers of - " << status_warranted << " students" << endl;
			for (int i = 0; i < count; i++) {
				cout << student[filtered_pid[i]].faculty_number << endl;
			}
		}
		
	}
	if (!flag) {
		cout << "No student with such status" << endl;
	}
	if(!flag2) {
		cout << "No students in information database" << endl;
	}
	return 0;
}
int separate_students_by_grades(student_info student[30]) {
	float min;
	float max;
	if (return_num_students(student) > 0) {
		cout << "Enter min for average of grades: ";
		cin >> min;
		cout << "Enter max for average of grades: ";
		cin >> max;

		int n = return_num_students(student);
		int filter_indices[30];
		int count = 0;
		calculate_average_grade(student);

		for (int i = 0; i < n; i++) {
			// Inside the loop
			/*std::cout << "min: " << min << ", max: " << max << ", sreden_uspeh: " << student[i].sreden_uspeh << std::endl;*/

			if (min <= student[i].sreden_uspeh && student[i].sreden_uspeh <= max) {
				filter_indices[count] = i; // Store the index of the student

				count++;
			}
		}

		// Sorting the filter_indices array
		for (int i = 0; i < count - 1; i++) {
			for (int j = 0; j < count - i - 1; j++) {
				// If the element found is greater than the next element, swap them
				if (filter_indices[j] > filter_indices[j + 1]) {
					// Swap filter_indices[j] and filter_indices[j+1]
					int temp = filter_indices[j];
					filter_indices[j] = filter_indices[j + 1];
					filter_indices[j + 1] = temp;
				}
			}
		}
		cout << "Personal ID numbers" << endl;
		for (int i = 0; i < count; i++) {
			cout << "Average grades of student -  " << student[filter_indices[i]].sreden_uspeh << endl;
			cout << "Personal Id number of student - " << student[filter_indices[i]].personal_id_number << endl;
		}
	}
	else {
		cout << "No students in information database" << endl;
	}
	
	return 0;
}
int change_data(student_info student[30]) {
	bool flag = false;
	string temp_faculty_number;
	string answer = "";
	if (return_num_students(student) > 0) {
		cout << "Enter faculty number of the student that you would like to update the information for" << endl;
		cin >> temp_faculty_number;
		for (int i = 0; i < return_num_students(student); i++) {
			if (temp_faculty_number == student[i].faculty_number) {
				flag = true;
				if (student[i].status_of_student == "active") {
					for (int z = 0; z < 5;z++) {
						if (student[i].disciplines[z].grade != 0) {
							cout << "Would you like to change the grade for - " << student[i].disciplines[z].name << " ? Enter Yes or no" << endl;
							cin >> answer;
							answer = convertToLowerCase(answer);
							while (answer != "yes" && answer != "no") {
								cout << "Enter valid answer - yes or no" << endl;
								cout << "Enter answer" << endl;
								cin >> answer;
							}
							answer = convertToLowerCase(answer);
							if (answer == "yes") {
								cout << "Enter grade for - " << student[i].disciplines[z].name << endl;
								cin >> student[i].disciplines[z].grade;
								calculate_average_grade(student);
							}
							else {
								continue;
							}
						}
						else if (student[i].disciplines[z].grade == 0) {
							cout << "Enter grade for - " << student[i].disciplines[z].name;
							cin >> student[i].disciplines[z].grade;
							calculate_average_grade(student);
						}
					}

				}
				else if (student[i].status_of_student == "graduated" || student[i].status_of_student == "dropout") {
					cout << "Cannot update grades for this student";
				}
			}
		}
		if (!flag) {
			cout << "Student not in the information database";
		}
	}
	else {
		cout << "No students in information database" << endl;
	}
	return 0;
}

int change_status_of_student(student_info student[30]) {
	string entered_faculty = "";
	bool flag = false;
	if (return_num_students(student) > 0) {
		cout << "Enter faculty number of student you would like to make changes for" << endl;
		cin >> entered_faculty;

		for (int i = 0; i < return_num_students(student);i++) {
			if (student[i].faculty_number == entered_faculty) {
				flag = true;
				if (student[i].status_of_student == "active" || student[i].status_of_student == "dropout")
				{

					cout << "Enter new status of student" << endl;
					cin >> student[i].status_of_student;
					student[i].status_of_student = convertToLowerCase(student[i].status_of_student);
				}
				else if (student[i].status_of_student == "graduated")
				{
					cout << "Cannot change status for graduated students" << endl;
				}
				else {
					cout << "Invalid status of student" << endl;
					cout << "Status must either be active, dropout or graduated" << endl;
				}

			}

		}
		if (!flag) {
			cout << "Enter faculty number not in information database" << endl;
		}
	} else {
		cout << "No students in information database" << endl;
	}

	
	return 0;
}
int menu_for_function_seperate_students_by_grades_or_status(student_info student[30]) {
	int choice;
	cout << "Enter 1 to seperate students by status" << endl;
	cout << "Enter 2 to seperate students by grades" << endl;
	cin >> choice;
	while (choice != 1 && choice != 2) {
		cout << "Error: Invalid option chosen. Enter 1 or 2" << endl;
		cin >> choice;
	}
	switch (choice) {
	case 1:
		seperate_students_by_status(student);
		break;
	case 2:
		separate_students_by_grades(student);
		break;
	}
	return 0;
}
int menu(student_info student[30]) {
	{
		
		int option;
		student_info student[30];
		cout << "Welcome to the Information system - Students - TU Varna" << endl;
		cout << "Press 1 to add students to a group" << endl;
		cout << "Press 2 to output all the students from the group" << endl;
		cout << "Press 3 to look for grades in BP in an interval or to look for students with fail grades" << endl;
		cout << "Press 4 to sort students by firstname" << endl;
		cout << "Press 5 to save changes to a file" << endl;
		cout << "Press 6 read student info from file" << endl;
		cout << "Press 7 to seperate students by grades or status" << endl;
		cout << "Press 8 change data for a student" << endl;
		cout << "Press 9 to change status of a student" << endl;
		cout << "Enter 0 to exit program" << endl;
		do {
		
			cout << "Enter option" << endl;
			cin >> option;
			while (option > 9) {
				cout << "Invalid option" << endl;
				cout << "Enter valid option" << endl;
				cin >> option;
			}


			switch (option) {
			case 1:
				input(student);
				calculate_average_grade(student);
				break;

			case 2:
				output(student);
				break;
			case 3:
				search_in_range_or_look_for_fail(student);
				break;
			case 4:
				sort_by_firstname(student);
				break;
			case 5:
				write_to_file(student);
				break;
			case 6:
				read_array_from_file(student);
				calculate_average_grade(student);
				break;
			case 7:
				menu_for_function_seperate_students_by_grades_or_status(student);
				break;
			case 8:
				change_data(student);
				break;
			case 9:
				change_status_of_student(student);
				break;
			case 0:
				break;
			}
		} while (option < 10 && option != 0);
		
	}
	write_to_file(student);
	return 0;

}

int main() {
	student_info student[30];
	int number_of_students = 0;

	// Read student information from the file
	number_of_students = read_array_from_file(student);
	calculate_average_grade(student);

	// Run the menu for user interaction
	menu(student);

	// Save the changes back to the file before exiting
	write_to_file(student);

	return 0;
}


