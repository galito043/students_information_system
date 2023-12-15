#include <iostream>
#include <string>
#include <fstream> 
using namespace std;
const int MAX_STUDENTS = 30;



struct discipline
{
	string name;
	int grade;
};


struct student_info {
	bool active;
	int faculty_number;
	int personal_id_number;
	string full_name;
	string gender;
	int age;
	string status_of_student;
	double sreden_uspeh;
	discipline disciplines[5] = {

		 {"Базово програмиране", 0},
		 {"Математика", 0},
		 {"Уеб дизайн", 0},
		 {"Електроника", 0},
		 {"Спорт", 0}
	};
};

int return_num_students(student_info studentInfo[30]) {
	int x = 0;
	for (int i = 0;;i++) {
		if (studentInfo[i].active != true) {
			x = i;
			break;
		}
	
	}
	return x;
}
int calculate_sreden_uspeh(student_info student[30]) {
	int actual_number_of_students = return_num_students(student);
	for (int i = 0; i < actual_number_of_students;i++) {
		student[i].sreden_uspeh = (student[i].disciplines[0].grade + student[i].disciplines[1].grade + student[i].disciplines[2].grade + student[i].disciplines[3].grade + student[i].disciplines[4].grade) / 5;

	}
	return 0;

}

int input(student_info studentInfo[30], int number_of_students){
	int current_number_of_students = return_num_students(studentInfo);
	
	cout <<"The current number of students is - " << current_number_of_students;
	if (number_of_students < 30) {
		for (int i = 0; i < number_of_students; i++) {
			int student_number = i + current_number_of_students;
			studentInfo[student_number].active = true;
			cout << "Enter faculty number\n";
			cin >> studentInfo[student_number].faculty_number;
			cout << "Enter personal ID number\n";
			cin >> studentInfo[student_number].personal_id_number;
			cout << "Enter full name\n";
			cin >> studentInfo[student_number].full_name;
			if (cin.fail())
			{
				cout << "Please enter a string";
				// clear error state
				cin.clear();
				// discard 'bad' character(s)
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cin >> studentInfo[student_number].full_name;
			}

			for (int z = 0; z < 5;z++) {
				cout << "Enter grade for - " << studentInfo[student_number].disciplines[z].name << endl;
				cin >> studentInfo[student_number].disciplines[z].grade;
				while (studentInfo[student_number].disciplines[z].grade < 0 || studentInfo[z].disciplines[z].grade == 1 || studentInfo[z].disciplines[z].grade > 6) {
					cout << "Wrong input for grade.Try again\n";
					cin >> studentInfo[student_number].disciplines[z].grade;
				}
			}

			cout << "Enter gender of student\n";
			cin >> studentInfo[student_number].gender;
			cout << "Enter age of student\n";
			cin >> studentInfo[student_number].age;
			cout << "Enter status of student\n";
			cin >> studentInfo[student_number].status_of_student;
		}
		/*number_of_students++;*/
	}
	
	return 0;
}
int output(student_info studentInfo[30], int number_of_students)
{
	int current_number_of_students = return_num_students(studentInfo);

	cout << "The current number of students is - " << current_number_of_students;
	cout << "*********-Table of students-*****************\n";
	for (int i = 0; i < current_number_of_students;i++) {
		cout << "Data of student -" << i << endl;
		cout << "Faculty number -  ";
		cout << studentInfo[i].faculty_number << endl;
		cout << "Personal ID number -  ";
		cout << studentInfo[i].personal_id_number << endl;
		cout << "Full name - ";
		cout << studentInfo[i].full_name << endl;
		for (int z = 0; z < 5; z++) {
			cout << studentInfo[i].disciplines[z].name << " grade -  " << studentInfo[i].disciplines[z].grade << endl;

		}
		cout << "Gender of student - " << studentInfo[i].gender << endl;
		cout << "Age of student - " << studentInfo[i].age << endl;
		cout << "Status of student - " << studentInfo[i].status_of_student << endl;
		cout << "End of info student - " << i << endl;
		cout << "-------------------------------------------\n";

	}
	cout << "*************-Table of students-*****************\n";
	return 0;
}
int search_in_range_or_look_for_fail(student_info studentInfo[30], int number_of_students)
{
	int option1;
	cout << "Enter option 1 to look for grades in a range. Enter option 2 to look for fail grades\n";
	cin >> option1;
	if (option1 == 1) {
		int lower_end, higher_end;
		cout << "Enter lower end";
		cin >> lower_end;
		cout << "Enter higher end";
		cin >> higher_end;
		for (int i = 0; i < number_of_students; i++)
		{
			if (studentInfo[i].disciplines[0].grade >= lower_end && studentInfo[i].disciplines[0].grade <= higher_end) {
				cout << studentInfo[i].full_name;
			}

		}

	}
	else if (option1 == 2) {
		for (int z = 0; z < number_of_students;z++) {
			if (studentInfo[z].disciplines[z].grade == 2) {
				cout << studentInfo[z].full_name;
			}
		}
	}
	else {
		cout << "Wrong input for option. Enter 1 or 2\n";
		cin >> option1;
	}




	return 0;
}
int swap(student_info& a, student_info&b)
{
	student_info temp = a;
	a = b;
	b = temp;
	return 0;
}



int sort_by_firstname(student_info student[30],int& number_of_students)
{
	int n = return_num_students(student);
	for (int i = 0; i < n - 1;i++) {
		for (int j = 0; j < n - i - 1;j++) {
			if (student[j].full_name > student[j + 1].full_name) {
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
int write_to_file(student_info student[30], int number_of_students) {
	std::ofstream ofs;
	ofs.open("test.txt");
	if (ofs.is_open())
	{
		ofs << "*********-Table of students-*****************\n";
		for (int i = 0; i < number_of_students;i++) {
			ofs << "Data of student -" << i << endl;
			ofs << "Faculty number -  ";
			ofs << student[i].faculty_number << endl;
			ofs << "Personal ID number -  ";
			ofs << student[i].personal_id_number << endl;
			ofs << "Full name - ";
			ofs << student[i].full_name << endl;
			for (int z = 0; z < 5; z++) {
				ofs << student[i].disciplines[z].name << " grade -  " << student[i].disciplines[z].grade << endl;

			}
			ofs << "Gender of student - " << student[i].gender << endl;
			ofs << "Age of student - " << student[i].age << endl;
			ofs << "Status of student - " << student[i].status_of_student << endl;
			ofs << "End of info student - " << i << endl;
			ofs << "-------------------------------------------\n";

		}
		ofs << "*************-Table of students-*****************\n";
		return 0;
	}
	/*std::cout << "Output operation successfully performed\n";*/
	ofs.close();
	return 0;
}
int read_array_from_file(student_info student[30], int number_of_students) {
	std::ifstream ifs("file_with_info.txt");

	if (ifs.is_open()) {
		int current_number_of_students = return_num_students(student);
		int i = 0;

		while (i < MAX_STUDENTS && ifs >> student[i + current_number_of_students].faculty_number) {
			int student_number = i + current_number_of_students;

			ifs >> student[student_number].personal_id_number;
			ifs.ignore(); // Ignore newline character
			std::getline(ifs, student[student_number].full_name);

			student[student_number].active = true;

			for (int z = 0; z < 5; z++) {
				ifs >> student[student_number].disciplines[z].grade; // Не чете колкото трябва оценки
				cout << student[student_number].disciplines[z].grade;
			}

			ifs >> student[student_number].gender
				>> student[student_number].age
				>> student[student_number].status_of_student;

			i++;
		}
	}
	return 0;
}

void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			// If the element found is greater than the next element, swap them
			if (arr[j] > arr[j + 1]) {
				// Swap arr[j] and arr[j+1]
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int seperate_students_by_status(student_info student[30]) {
	string status_warranted;
	int count = 0;
	cout << "Enter status you would like to filter by\n";
		cin >> status_warranted;
		int filtered_pid[30];
	
	for (int i = 0; i < return_num_students(student); i++) {
		if (student[i].status_of_student == status_warranted) {
			filtered_pid[i] = student[i].faculty_number;
			count++;
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
	for (int i = 0; i < count; i++) {
		cout << filtered_pid[i] << endl;
	}
	return 0;
}
int seperate_students_by_grades(student_info student[30]) {
	float min;
	float max;
	cout << "Enter min";
	cin >> min;
	cout << "Enter max";
	cin >> max;
	int n = return_num_students(student);
	int filter_count[30];
	int count = 0;
	calculate_sreden_uspeh(student);

	for (int i = 0; i < n; i++) {
		if (min <= student[i].sreden_uspeh && student[i].sreden_uspeh <= max) {
			filter_count[i] = student[i].personal_id_number;
			count++;
		}
	}
	n = count;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			// If the element found is greater than the next element, swap them
			if (filter_count[j] > filter_count[j + 1]) {
				// Swap arr[j] and arr[j+1]
				int temp = filter_count[j];
				filter_count[j] = filter_count[j + 1];
				filter_count[j + 1] = temp;
			}
			
		}
		
	}
	for (int i = 0; i < count;i++) {
		cout << filter_count[i] << endl;
	}
	return 0;
}


	
int main()
{
	cout << "Welcome to the Information system - Students - TU Varna" << endl;
	cout << "Enter 0 to learn about the possible functions of this program" << endl;

	int option, option_info_menu;
	cin >> option_info_menu;
	student_info student[30];
	int number_of_students = 0;


	switch (option_info_menu) {
	case 0:
		cout << "Press 1 to add students to a group" << endl;
		cout << "Press 2 to output all the students from the group" << endl;
		cout << "Press 3 to look for grades in BP in an interval" << endl;
		break;
	}
	int sum_of_students = 0;
	do {
		
		cout << "Enter option";
		cin >> option;
		

			switch (option) {
			case 1:
				
				cout << "Enter number of students you would like to add \n";
				cin >> number_of_students;
				
				
				
				while (number_of_students > 30 || number_of_students < 1) {
					cout << "Error: Number of students either over 30 or lesser than 1";
					cin >> number_of_students;
				}
				input(student, number_of_students);
				break;

			case 2:
				output(student, number_of_students);
				break;
			case 3:
				search_in_range_or_look_for_fail(student, number_of_students);
				break;
			case 4:
				/*int n = sizeof(student) / sizeof(student[0]);*/
				sort_by_firstname(student, sum_of_students);
				break;
			case 5:
				write_to_file(student, number_of_students);
				break;
			case 6:
				read_array_from_file(student, number_of_students);
				break;
			case 7:
				seperate_students_by_status(student);
				break;
			case 8: 
				seperate_students_by_grades(student);
				break;
			}
		} while (option != 9 && option != 0);
		return 0;
	}

