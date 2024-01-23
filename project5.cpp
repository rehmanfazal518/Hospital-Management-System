#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct Date {   
	int day,month,year;
};

struct Patient {
	char Name[20], CNIC[14], disease[15];
	int id,age;
	Date doa,dod;
} P[20];

struct Rooms {
	char Type[10];
	int Room_No, No_beds,Beds_Occupied,Beds_Unoccupied;
} R[20];

struct Doctor {
	char Name[10],Qualification[10];
	int id,Year_of_experience;
} D[20];

struct Nurses {
	char Name[10];
	int id,Year_of_Experience;
} N[20];

struct Ward_boys {
	char Name[10];
	int id,Year_of_Experience;
} W[20];

struct Sweeper {
	char Name[10];
	int id,Years_OF_Work;
} S[10];

void main_choice();
void add_record();		// add record
void p_add_record();
void r_add_record();
void n_add_record();
void w_add_record();
void s_add_record();
void d_add_record();
void view_record();		// view record
void d_view_record();    
void wardboy_view_record();
void patient_view_record();
void room_view_record();
void nurses_view_record();
void sweeper_view_record();
void delete_record();	// delete record 
void doctor_delete_record();
void patient_delete_record();
void wardboy_delete_record();
void room_delete_record();
void nurses_delete_record();
void sweeper_delete_record();
void modify_record();	// modify record 
void patient_modify_record();
void doctor_modify_record();
void nurses_modify_record();
void wardboy_modify_record();
void sweeper_modify_record();
void room_modify_record();
void hospital_Bill();	//Hospital Bill
void discharched_Certificate();		//Discharged certificate

int main() {      //Main Block
	int i;
	do {
		main_choice();
		printf("If you want to go to the Main Menu, then enter 1 and if not then enter any number other than 1 : ");
		scanf("%d",&i);
	} while(i==1);
	printf("Exiting..............");
}

void main_choice() {			//Main Menu
	system("cls");
	printf("\t\t\t#######################################################\n\t\t\t\tWELCOME TO HOSPITAL MANAGEMENT SYSTEM\n\t\t\t#######################################################\n");
	int choice;
	printf("1. Add Record \n\n2. View Record\n\n3. Delete Record\n\n4. Modify Record\n\n5. Calculate Bill\n\n6. Discharged Certificate\n\n\nEnter Your Chooice : ");
	scanf("%d",&choice);
	if(choice==1)
		add_record();
	else if(choice==2)
		view_record();
	else if(choice==3)
		delete_record();
	else if(choice==4)
		modify_record();
	else if(choice==5)
		hospital_Bill();
	else if(choice==6)
		discharched_Certificate();
	else {
		system("cls");
		printf("Wrong Input.\n\n");
	}
}

void add_record() {			//Menu For Add Record
	system("cls");
	int choice;
	printf("1. Doctors\n\n2. Ward Boys\n\n3. Rooms\n\n4. Sweepers\n\n5. Patients\n\n6. Nurses\n\n\nEnter Your Choice : ");
	scanf("%d",&choice);
	if (choice==1)
		d_add_record();
	else if(choice==2)
		w_add_record();
	else if(choice==3)
		r_add_record();
	else if(choice==4)
		s_add_record();
	else if(choice==5)
		p_add_record();
	else if (choice==6)
		n_add_record();
	else
		printf("\nWrong input.\n\n");
}

void view_record() {      //Menu For View Record
	system("cls");
	int choice;
	printf("1. Doctors\n\n2. Ward Boys\n\n3. Rooms\n\n4. Sweepers\n\n5. Patients\n\n6. Nurses\n\nEnter Your Choice :");
	scanf("%d",&choice);
	if (choice==1)
		d_view_record();
	else if(choice==2)
		wardboy_view_record();
	else if(choice==3)
		room_view_record();
	else if(choice==4)
		sweeper_view_record();
	else if(choice==5)
		patient_view_record();
	else if(choice==6)
		nurses_view_record();
	else printf("\nWrong input.\n\n");
}

void delete_record() {       //Menu For Delete Record
	system("cls");
	int choice;
	printf("1. Doctors\n\n2. Ward-Boys\n\n3. Rooms\n\n4. Sweepers\n\n5. Patients\n\n6. Nurses\n\nEnter Your Choice :");
	scanf("%d",&choice);
	if (choice==1)
		doctor_delete_record();
	else if(choice==2)
		wardboy_delete_record();
	else if(choice==3)
		room_delete_record();
	else if(choice==4)
		sweeper_delete_record();
	else if(choice==5)
		patient_delete_record();
	else if(choice==6)
		nurses_delete_record();
	else printf("\nWrong choice\n");

}

void modify_record() {       //Menu For Modify Record
	system("cls");
	int choice;
	printf("1. Doctors\n\n2. Ward-Boys\n\n3. Rooms\n\n4. Sweepers\n\n5. Patients\n\n6. Nurses\n\nEnter Your Choice :");
	scanf("%d",&choice);
	if (choice==1)
		doctor_modify_record();
	else if(choice==2)
		wardboy_modify_record();
	else if(choice==3)
		room_modify_record();
	else if(choice==4)
		sweeper_modify_record();
	else if(choice==5)
		patient_modify_record();
	else if(choice==6)
		nurses_modify_record();
	else printf("\nWrong choice\n");
}

void d_add_record() {        //Add Record Function For Doctor
	system("cls");
	FILE *Doctor;
	int c;
	int i;
	do {
		Doctor = fopen("Doctor_Records.txt", "a");
		i=0;
			printf("Enter ID : ");
			scanf("%d",&D[i].id);
			printf("Enter Name : ");
			scanf("%s",D[i].Name);
			printf("Enter Qualification : ");
			scanf("%s",D[i].Qualification);
			printf("Enter Years Of Working : ");
			scanf("%d",&D[i].Year_of_experience);
			fprintf(Doctor,"%d\n%s\n%d\n%s\n\n",D[i].id,D[i].Name,D[i].Year_of_experience,D[i].Qualification);
		
		fclose(Doctor);
		printf ("\n\tDo you want to add the record of any other doctor?\n\tIf yes then enter 1 and if no then enter any number other than 1 : "); //asking user if the user wants to enter another record or not
		scanf ("%d",&c);
		printf("\n");
	} while(c==1);
}

void d_view_record() {          //View Record Function For Doctor
	system("cls");
	FILE *Doctor;
	int i=0,j;
	Doctor=fopen("Doctor_Records.txt", "r");
	printf("\t\t\tTHE LIST OF DOCTORS:\n");
	printf("\t\t\t*********************\n");
	while(!feof(Doctor)) {
		fscanf(Doctor,"%d\n%s\n%d\n%s\n\n",&D[i].id,D[i].Name,&D[i].Year_of_experience,D[i].Qualification);
		i++;
	}
	for(j=0; j<i; j++) {
		printf("ID : %d\nName : %s\nExperience : %d year\nQualification : %s\n",D[j].id,D[j].Name,D[j].Year_of_experience,D[j].Qualification);
		printf("==================================================================\n");
	}
	fclose(Doctor);
}

void doctor_delete_record() {            //Delete Record Function For Doctor
	system("cls");
	FILE *Doctor;
	int i=0,j,x;
	Doctor=fopen("Doctor_Records.txt", "r");
	printf("\t\t\tTHE LIST OF DOCTORS:\n");
	printf("\t\t\t*********************\n");
	while(!feof(Doctor)) {
		fscanf(Doctor,"%d\n%s\n%d\n%s\n\n",&D[i].id,D[i].Name,&D[i].Year_of_experience,D[i].Qualification);
		i++;
	}
	for(j=0; j<i; j++) {
		printf("Index : %d\n",j);
		printf("ID : %d\nName : %s\nQualification : %d\nExperience : %s year\n",D[j].id,D[j].Name,D[j].Year_of_experience,D[j].Qualification);
		printf("==================================================================\n");
	}
	fclose(Doctor);
	Doctor = fopen("Doctor_Records.txt", "w");
	printf("\nEnter the index shown with the record of the Doctor, whose record you want to delete : ");
	scanf("%d",&x);
	printf("\n");
	for(j=0; j<i; j++) {
		if(j==x) {
			continue;
		}
		fprintf(Doctor,"%d\n%s\n%d\n%s\n\n",D[j].id,D[j].Name,D[j].Year_of_experience,D[j].Qualification);
	}
	fclose(Doctor);
	printf("\t\t\tThe record has been DELETED.\n\n");
}

void doctor_modify_record() {         //Modify Record Function For Doctor
	system("cls");
	FILE *Doctor;
	Doctor=fopen("Doctor_Records.txt", "r");
	int i=0,j;
	while(!feof(Doctor)) {
		fscanf(Doctor,"%d\n%s\n%d\n%s\n\n",&D[i].id,D[i].Name,&D[i].Year_of_experience,D[i].Qualification);
		i++;
	}
	
	for(j=0; j<i; j++) {
		printf("ID : %d\nName : %s\nQualification : %d\nExperience : %s year\n",D[j].id,D[j].Name,D[j].Year_of_experience,D[j].Qualification);
		printf("==================================================================\n");
	}
	fclose(Doctor);
	
	int id;
	printf("\n\nEnter the ID of Doctor whose record you want to modify : ");
	scanf("%d",&id);
	printf("\n");
	for(j=0; j<i; j++) {
		if(D[j].id==id) {
			break;
		}
	}
	if(j==i) {
		printf("\n\nThe ID you entered does not match with the ID of any Doctor.\n\n");
	} else {
		int choice;
		int check;
		do {
			system("cls");
			printf("\n\nWhat thing you want to modify?\n\n");
			printf("1. ID\n2. Name\n3. Years of experience\n4. Qualification\n\n");
			printf("Enter the number associated with your choice : ");
			scanf("%d",&choice);
			switch(choice) {
				case 1: {
					printf("\nEnter  NEW ID for Doctor : ");
					scanf("%d",&D[j].id);
					break;
				}
				case 2: {
					printf("\nEnter NEW Name for Doctor : ");
					scanf("%s",D[j].Name);
					break;
				}
				case 3: {
					printf("\nEnter NEW Years of Experience : ");
					scanf("%d",&D[j].Year_of_experience);
					break;
				}
				case 4: {
					printf("\nEnter NEW Qualification for Doctor : ");
					scanf("%s",D[j].Qualification);
					break;
				}
				default:
					printf("\nWrong input.");
			}
			printf("\n\n\tDo you want to modify any other thing of the same Doctor?\n\tIf yes then enter 1 and if no then enter any number other than 1 : ");
			scanf("%d",&check);
			printf("\n");
		} while(check==1);
		Doctor=fopen("Doctor_Records.txt", "w");
		for(j=0; j<i; j++) {
			fprintf(Doctor,"%d\n%s\n%d\n%s\n\n",D[j].id,D[j].Name,D[j].Year_of_experience,D[j].Qualification);
		}
		fclose(Doctor);
	}
}

void w_add_record() {           //Add Record Function For Ward Boy
	system("cls");
	FILE *Ward_BOYS;
	int c;
	int i;
	do {
		Ward_BOYS = fopen("Ward_BOYS_Records.txt", "a");
		i=0;
			printf("Enter ID : ");
			scanf("%d",&W[i].id);
			printf("Enter Name : ");
			scanf("%s",&W[i].Name);
			printf("Enter Years Of Experience : ");
			scanf("%d",&W[i].Year_of_Experience);
			fprintf(Ward_BOYS,"%d\n%s\n%d\n\n",W[i].id,W[i].Name,W[i].Year_of_Experience);
		fclose(Ward_BOYS);
		printf ("\n\tDo you want to add the record of any other ward boy?\n\tIf yes then enter 1 and if no then enter any number other than 1 : "); //asking user if the user wants to enter another record or not
		scanf ("%d",&c);
		printf("\n");
	} while(c==1);
}

void wardboy_view_record() {
	system("cls");
	FILE *Ward_BOYS;
	int i=0,j;
	Ward_BOYS=fopen("Ward_BOYS_Records.txt", "r");
	printf("\t\t\tTHE LIST OF WARD BOYS:\n");
	printf("\t\t\t*********************\n");
	while(!feof(Ward_BOYS)) {
		fscanf(Ward_BOYS,"%d\n%s\n%d\n\n",&W[i].id,&W[i].Name,&W[i].Year_of_Experience);
		i++;
	}
	for(j=0; j<i; j++) {
		printf("ID : %d\nName : %s\nExperience : %d year\n",W[j].id,W[j].Name,W[j].Year_of_Experience);
		printf("==================================================================\n");
	}
	fclose(Ward_BOYS);
}

void wardboy_delete_record() {
	system("cls");
	FILE *Ward_BOYS;
	int i=0,j,x;
	Ward_BOYS=fopen("Ward_BOYS_Records.txt", "r");
	printf("\t\t\tTHE LIST OF WARD BOYS:\n");
	printf("\t\t\t*********************\n");
	while(!feof(Ward_BOYS)) {
		fscanf(Ward_BOYS,"%d\n%s\n%d\n\n",&W[i].id,W[i].Name,&W[i].Year_of_Experience);
		i++;
	}
	for(j=0; j<i; j++) {
		printf("Index=%d\n",j);
		printf("ID : %d\nName : %s\nExperience : %d year\n",W[j].id,W[j].Name,W[j].Year_of_Experience);
		printf("==================================================================\n");
	}
	fclose(Ward_BOYS);

	Ward_BOYS = fopen("Ward_BOYS_Records.txt", "w");
	printf("Enter the index shown with the record of the ward boy, whose record you want to delete : ");
	scanf("%d",&x);
	printf("\n");
	for(j=0; j<i; j++) {
		if(j==x) {
			continue;
		}
		fprintf(Ward_BOYS,"%d\n%s\n%d\n\n",W[j].id,W[j].Name,W[j].Year_of_Experience);
	}
	fclose(Ward_BOYS);
	printf("\t\t\tThe record has been DELETED.\n\n");
}

void wardboy_modify_record() {
	system("cls");
	FILE *Ward_BOYS;
	Ward_BOYS=fopen("Ward_BOYS_Records.txt", "r");
	int i=0,j;
	while(!feof(Ward_BOYS)) {
		fscanf(Ward_BOYS,"%d\n%s\n%d\n\n",&W[i].id,W[i].Name,&W[i].Year_of_Experience);
		i++;
	}
	for(j=0; j<i; j++) {
		printf("ID : %d\nName : %s\nExperience : %d year\n",W[j].id,W[j].Name,W[j].Year_of_Experience);
		printf("==================================================================\n");
	}
	fclose(Ward_BOYS);
	int id;
	printf("\n\nEnter the ID of Ward Boy whose record you want to modify : ");
	scanf("%d",&id);
	for(j=0; j<i; j++) {
		if(W[j].id==id) {
			break;
		}
	}
	if(j==i) {
		printf("\n\nThe ID you entered does not match with the ID of any Ward Boy.\n\n");
	} else {
		int choice;
		int check;
		do {
			system("cls");
			printf("\n\nWhat thing you want to modify?\n\n");
			printf("1. ID\n2. Name\n3. Years of experience\n\n");
			printf("Enter the number associated with your choice : ");
			scanf("%d",&choice);
			switch(choice) {
				case 1: {
					printf("\nEnter NEW ID for Ward Boy : ");
					scanf("%d",&W[j].id);
					break;
				}
				case 2: {
					printf("\nEnter NEW Name for Ward Boy : ");
					scanf("%s",W[j].Name);
					break;
				}
				case 3: {
					printf("\nEnter NEW Years for Experience : ");
					scanf("%d",&W[j].Year_of_Experience);
					break;
				}
				default:
					printf("\nWrong input.");
			}
			printf("\n\n\tDo you want to modify any other thing of the same Ward Boy?\n\tIf yes then enter 1 and if no then enter any number other than 1 : ");
			scanf("%d",&check);
			printf("\n");
		} while(check==1);
		Ward_BOYS=fopen("Ward_BOYS_Records.txt", "w");
		for(j=0; j<i; j++) {
			fprintf(Ward_BOYS,"%d\n%s\n%d\n\n",W[j].id,W[j].Name,W[j].Year_of_Experience);
		}
		fclose(Ward_BOYS);
	}
}

void p_add_record() {		// ADD Patient Record
	system("cls");
	FILE *Patient;
	int i;
	int c;
	Patient = fopen("Patient_Records.txt", "a");
	do {
		i=0;
			printf("Enter ID : ");
			scanf("%d",&P[i].id);
			printf("Enter Name : ");
			scanf("%s",P[i].Name);
			printf("Enter Age : ");
			scanf("%d",&P[i].age);
			printf("Enter CNIC : ");
			scanf("%s",P[i].CNIC);
			printf("Enter Disease : ");
			scanf("%s",P[i].disease);
			printf("Enter Date of Admission :\n");
			printf("Day : ");
			scanf("%d",&P[i].doa.day);
			printf("Month : ");
			scanf("%d",&P[i].doa.month);
			printf("Year : ");
			scanf("%d",&P[i].doa.year);
			printf("Enter Date Of Discharged :\n");
			printf("Day : ");
			scanf("%d",&P[i].dod.day);
			printf("Month : ");
			scanf("%d",&P[i].dod.month);
			printf("Year : ");
			scanf("%d",&P[i].dod.year);
			fprintf(Patient,"%d\n%s\n%d\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n\n",P[i].id,P[i].Name,P[i].age,P[i].CNIC,P[i].disease,P[i].doa.day,P[i].doa.month,P[i].doa.year,P[i].dod.day,P[i].dod.month,P[i].dod.year);
		printf ("\n\tDo you want to add the record of any other patient?\n\tIf yes then enter 1 and if no then enter any number other than 1 : "); //asking user if the user wants to enter another record or not
		scanf ("%d",&c);
		printf("\n");
	} while(c==1);
	fclose(Patient);
}

void patient_view_record() {			//Patient view Function
	system("cls");
	FILE *patient;
	patient=fopen("Patient_Records.txt", "r");
	int i=0,j;
	printf("\t\t\tTHE LIST OF PATIENTS:\n");
	printf("\t\t\t*********************\n");
	while(!feof(patient)) {
		fscanf(patient,"%d\n%s\n%d\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n\n",&P[i].id,&P[i].Name,&P[i].age,&P[i].CNIC,&P[i].disease,&P[i].doa.day,&P[i].doa.month,&P[i].doa.year,&P[i].dod.day,&P[i].dod.month,&P[i].dod.year);
		i++;
	}
	for(j=0; j<i; j++) {
		printf("ID : %d\nNAME : %s\nAGE : %d\nCNIC : %s\nDISEASE : %s\nADMISSION DATE : %d-%d-%d\nDISCHARGED DATE : %d-%d-%d\n\n",P[j].id,P[j].Name,P[j].age,P[j].CNIC,P[j].disease,P[j].doa.day,P[j].doa.month,P[j].doa.year,P[j].dod.day,P[j].dod.month,P[j].dod.year);
		printf("==================================================================\n");
	}
	fclose(patient);
}

void patient_delete_record() {			//Patient Delete Function
	system("cls");
	FILE *patient;
	int i=0,j,x;
	patient = fopen("Patient_Records.txt", "r");
	printf("\t\t\tTHE LIST OF PATIENTS:\n");
	printf("\t\t\t*********************\n");
	while(!feof(patient)) {
		fscanf(patient,"%d\n%s\n%d\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n\n",&P[i].id,&P[i].Name,&P[i].age,&P[i].CNIC,&P[i].disease,&P[i].doa.day,&P[i].doa.month,&P[i].doa.year,&P[i].dod.day,&P[i].dod.month,&P[i].dod.year);
		i++;
	}
	for(j=0; j<i; j++) {
		printf("Index=%d\n",j);
		printf("ID : %d\nNAME : %s\nAGE : %d\nCNIC : %s\nDISEASE : %s\nADMISSION DATE : %d-%d-%d\nDISCHARGED DATE : %d-%d-%d\n\n",P[j].id,P[j].Name,P[j].age,P[j].CNIC,P[j].disease,P[j].doa.day,P[j].doa.month,P[j].doa.year,P[j].dod.day,P[j].dod.month,P[j].dod.year);
		printf("==================================================================\n");
	}
	fclose(patient);

	patient = fopen("Patient_Records.txt", "w");
	printf("Enter the index shown with the record of the patient, whose record you want to delete : ");
	scanf("%d",&x);
	printf("\n");
	for(j=0; j<i; j++) {
		if(j==x) {
			continue;
		}
		fprintf(patient,"%d\n%s\n%d\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n\n",P[j].id,P[j].Name,P[j].age,P[j].CNIC,P[j].disease,P[j].doa.day,P[j].doa.month,P[j].doa.year,P[j].dod.day,P[j].dod.month,P[j].dod.year);
	}
	fclose(patient);
	printf("\t\t\tThe record has been DELETED.\n\n");
}

void patient_modify_record() {
	system("cls");
	FILE *patient;
	patient=fopen("Patient_Records.txt", "r");
	int i=0,j;
	while(!feof(patient)) {
		fscanf(patient,"%d\n%s\n%d\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n\n",&P[i].id,&P[i].Name,&P[i].age,&P[i].CNIC,&P[i].disease,&P[i].doa.day,&P[i].doa.month,&P[i].doa.year,&P[i].dod.day,&P[i].dod.month,&P[i].dod.year);
		i++;
	}
	for(j=0;j<i;j++)
	{
		printf("ID : %d\nNAME : %s\nAGE : %d\nCNIC : %s\nDISEASE : %s\nADMISSION DATE : %d-%d-%d\nDISCHARGED DATE : %d-%d-%d\n\n",P[j].id,P[j].Name,P[j].age,P[j].CNIC,P[j].disease,P[j].doa.day,P[j].doa.month,P[j].doa.year,P[j].dod.day,P[j].dod.month,P[j].dod.year);
		printf("==================================================================\n");
	}
	fclose(patient);
	int id;
	printf("\n\nEnter the ID of patient whose record you want to modify : ");
	scanf("%d",&id);
	for(j=0; j<i; j++) {
		if(P[j].id==id) {
			break;
		}
	}
	if(j==i) {
		printf("\n\nThe ID you entered does not match with the ID of any patient.\n\n");
	} else {
		int choice;
		int check;
		do {
			system("cls");
			printf("\n\nWhat thing you want to modify?\n\n");
			printf("1. Name\n2. CNIC\n3. ID\n4. Age\n5. Admission Date\n6. Discharged Date\n7. Disease\n\n");
			printf("Enter the number associated with your choice: ");
			scanf("%d",&choice);
			switch(choice) {
				case 1: {
					printf("\nEnter NEW name for patient : ");
					scanf("%s",P[j].Name);
					break;
				}
				case 2: {
					printf("\nEnter NEW CNIC for patient : ");
					scanf("%s",P[j].CNIC);
					break;
				}
				case 3: {
					printf("\nEnter NEW ID for patient : ");
					scanf("%d",&P[j].id);
					break;
				}
				case 4: {
					printf("\nEnter NEW age for patient : ");
					scanf("%d",&P[j].age);
					break;
				}
				case 5: {
					printf("Enter NEW day of admission : ");
					scanf("%d",&P[j].doa.day);
					printf("Enter NEW month of admission : ");
					scanf("%d",&P[j].doa.month);
					printf("Enter NEW year of admission : ");
					scanf("%d",&P[j].doa.year);
					break;
				}
				case 6: {
					printf("Enter NEW day of discharge : ");
					scanf("%d",&P[j].dod.day);
					printf("Enter NEW month of discharge : ");
					scanf("%d",&P[j].dod.month);
					printf("Enter NEW year of discharge : ");
					scanf("%d",&P[j].dod.year);
					break;
				}
				case 7: {
					printf("Enter NEW disease for the patient : ");
					scanf("%s",P[j].disease);
					break;
				}
				default:
					printf("\nWrong input.");
			}
			printf("\n\n\tDo you want to modify any other thing of the same Ward Boy?\n\tIf yes then enter 1 and if no then enter any number other than 1 : ");
			scanf("%d",&check);
			printf("\n");
		} while(check==1);
		patient=fopen("Patient_Records.txt", "w");
		for(j=0; j<i; j++) {
			fprintf(patient,"%d\n%s\n%d\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n\n",P[j].id,P[j].Name,P[j].age,P[j].CNIC,P[j].disease,P[j].doa.day,P[j].doa.month,P[j].doa.year,P[j].dod.day,P[j].dod.month,P[j].dod.year);
		}
		fclose(patient);
	}
}

void r_add_record() { // ADDS ROOMS Record
	system("cls");
	FILE *Rooms;
	int c;
	int i;
	do {
		Rooms = fopen("Rooms_Records.txt", "a");
		i=0;
			printf("Enter Room No. : ");
			scanf("%d",&R[i].Room_No);
			printf("Enter Room Type : ");
			scanf("%s",&R[i].Type);
			printf("Enter Total No. of Beds in the Room : ");
			scanf("%d",&R[i].No_beds);
			printf("Enter the No. of Occupied Beds : ");
			scanf("%d",&R[i].Beds_Occupied);
			printf("Enter the No. of Unoccupied Beds : ");
			scanf("%d",&R[i].Beds_Unoccupied);
			fprintf(Rooms,"%d\n%s\n%d\n%d\n%d\n\n",R[i].Room_No,R[i].Type,R[i].No_beds,R[i].Beds_Occupied,R[i].Beds_Unoccupied);
		fclose(Rooms);
		printf ("\n\tDo you want to add the record of any other room?\n\tIf yes then enter 1 and if no then enter any number other than 1 : "); //asking user if the user wants to enter another record or not
		scanf ("%d",&c);
		printf("\n");
	} while(c==1);
}

void room_view_record() {
	system("cls");
	FILE *Rooms;
	int i=0,j;
	Rooms=fopen("Rooms_Records.txt", "r");
	printf("\t\t\tTHE LIST OF ROOMS:\n");
	printf("\t\t\t*********************\n");
	while(!feof(Rooms)) {
		fscanf(Rooms,"%d\n%s\n%d\n%d\n%d\n\n",&R[i].Room_No,&R[i].Type,&R[i].No_beds,&R[i].Beds_Occupied,&R[i].Beds_Unoccupied);
		i++;
	}
	for(j=0; j<i; j++) {
		printf("Room No. : %d\n\nRoom Type : %s\n\nTotal No. of Beds in the Rooms : %d\n\nNo. of Occupied Beds : %d\n\nNo. of Unoccupied Beds : %d\n\n",R[j].Room_No,R[j].Type,R[j].No_beds,R[j].Beds_Occupied,R[j].Beds_Unoccupied);
		printf("==================================================================\n");
	}
	fclose(Rooms);
}

void room_delete_record() {
	system("cls");
	FILE *Rooms;
	int i=0,j,x;
	Rooms=fopen("Rooms_Records.txt", "r");
	printf("\t\t\tTHE LIST OF ROOMS:\n");
	printf("\t\t\t*********************\n");
	while(!feof(Rooms)) {
		fscanf(Rooms,"%d\n%s\n%d\n%d\n%d\n\n",&R[i].Room_No,&R[i].Type,&R[i].No_beds,&R[i].Beds_Occupied,&R[i].Beds_Unoccupied);
		i++;
	}
	for(j=0; j<i; j++) {
		printf("Index=%d\n\n",j);
		printf("Room No. : %d\n\nRoom Type : %s\n\nTotal No. of Beds in the Rooms : %d\n\nNo. of Occupied Beds : %d\n\nNo. of Unoccupied Beds : %d\n\n",R[j].Room_No,R[j].Type,R[j].No_beds,R[j].Beds_Occupied,R[j].Beds_Unoccupied);
		printf("==================================================================\n");
	}

	fclose(Rooms);
	Rooms = fopen("Rooms_Records.txt", "w");
	printf("Enter the index shown with the record of the room, whose record you want to delete : ");
	scanf("%d",&x);
	printf("\n");
	for(j=0; j<i; j++) {
		if(j==x) {
			continue;
		}
		fprintf(Rooms,"%d\n%s\n%d\n%d\n%d\n\n",R[j].Room_No,R[j].Type,R[j].No_beds,R[j].Beds_Occupied,R[j].Beds_Unoccupied);
	}
	fclose(Rooms);
	printf("\t\t\tThe record has been DELETED.\n\n");
}

void room_modify_record() {
	system("cls");
	FILE *Rooms;
	Rooms=fopen("Rooms_Records.txt", "r");
	int i=0,j;
	while(!feof(Rooms)) {
		fscanf(Rooms,"%d\n%s\n%d\n%d\n%d\n\n",&R[i].Room_No,&R[i].Type,&R[i].No_beds,&R[i].Beds_Occupied,&R[i].Beds_Unoccupied);
		i++;
	}
	for(j=0; j<i; j++) {
		printf("Index=%d\n\n",j);
		printf("Room No. : %d\n\nRoom Type : %s\n\nTotal No. of Beds in the Rooms : %d\n\nNo. of Occupied Beds : %d\n\nNo. of Unoccupied Beds : %d\n\n",R[j].Room_No,R[j].Type,R[j].No_beds,R[j].Beds_Occupied,R[j].Beds_Unoccupied);
		printf("==================================================================\n");
	}
	fclose(Rooms);
	int id;
	printf("\n\nEnter the Room No. of the room, whose record you want to modify : ");
	scanf("%d",&id);
	for(j=0; j<i; j++) {
		if(R[j].Room_No==id) {
			break;
		}
	}
	if(j==i) {
		printf("\n\nThe Room No. you entered, does not match with the room no. of any room.\n\n");
	} else {
		int choice;
		int check;
		do {
			system("cls");
			printf("\n\nWhat thing you want to modify?\n\n");
			printf("1. Room No.\n2. Type\n3. Total No. of Beds\n4. No. of Occupied Beda\n5. No. of Unoccupied Beds\n\n");
			printf("Enter the number associated with your choice : ");
			scanf("%d",&choice);
			switch(choice) {
				case 1: {
					printf("\nEnter NEW Room No. : ");
					scanf("%d",&R[j].Room_No);
					break;
				}
				case 2: {
					printf("\nEnter NEW Room Type : ");
					scanf("%s",R[j].Type);
					break;
				}
				case 3: {
					printf("\nEnter NEW Total No. of Beds : ");
					scanf("%d",&R[j].No_beds);
					break;
				}
				case 4: {
					printf("\nEnter NEW No. of Occupied Beds : ");
					scanf("%d",&R[j].Beds_Occupied);
					break;
				}
				case 5: {
					printf("Enter NEW No. of Unoccupied Beds : ");
					scanf("%d",&R[j].Beds_Unoccupied);
					break;
				}
				default:
					printf("\nWrong input.");
			}
			printf("\n\n\tDo you want to modify any other thing of the same Ward Boy?\n\tIf yes then enter 1 and if no then enter any number other than 1 : ");
			scanf("%d",&check);
			printf("\n");
		} while(check==1);
		Rooms=fopen("Rooms_Records.txt", "w");
		for(j=0; j<i; j++) {
			fprintf(Rooms,"%d\n%s\n%d\n%d\n%d\n\n",R[j].Room_No,R[j].Type,R[j].No_beds,R[j].Beds_Occupied,R[j].Beds_Unoccupied);
		}
		fclose(Rooms);
	}
}

void n_add_record() {	// ADD Nurses Record
	system("cls");
	FILE *Nurses;
	int c;
	int i;
	do {
		Nurses = fopen("Nurses_Records.txt", "a");
		i=0;
			printf("Enter ID : ");
			scanf("%d",&N[i].id);
			printf("Enter Name : ");
			scanf("%s",&N[i].Name);
			printf("Enter Years Of Experience : ");
			scanf("%d",&N[i].Year_of_Experience);
			fprintf(Nurses,"%d\n%s\n%d\n\n",N[i].id,N[i].Name,N[i].Year_of_Experience);
		fclose(Nurses);
		printf ("\n\tDo you want to add the record of any other nurse?\n\tIf yes then enter 1 and if no then enter any number other than 1 : "); //asking user if the user wants to enter another record or not
		scanf ("%d",&c);
		printf("\n");
	} while(c==1);
}

void nurses_view_record() {
	system("cls");
	FILE *Nurses;
	int i=0,j;
	Nurses=fopen("Nurses_Records.txt", "r");
	printf("\t\t\tTHE LIST OF NURSES:\n");
	printf("\t\t\t*********************\n");
	while(!feof(Nurses)) {
		fscanf(Nurses,"%d\n%s\n%d\n\n",&N[i].id,&N[i].Name,&N[i].Year_of_Experience);
		i++;
	}
	for(j=0; j<i; j++) {
		printf("ID : %d\nName : %s\nExperience : %d years\n\n",N[j].id,N[j].Name,N[j].Year_of_Experience);
		printf("==================================================================\n");
	}
	fclose(Nurses);
}

void nurses_delete_record() {
	system("cls");
	FILE *Nurses;
	int i=0,j,x;
	Nurses=fopen("Nurses_Records.txt", "r");
	printf("\t\t\tTHE LIST OF NURSES:\n");
	printf("\t\t\t*********************\n");
	while(!feof(Nurses)) {
		fscanf(Nurses,"%d\n%s\n%d\n\n",&N[i].id,&N[i].Name,&N[i].Year_of_Experience);
		i++;
	}
	for(j=0; j<i; j++) {
		printf("Index=%d\n",j);
		printf("ID : %d\nName : %s\nExperience : %d years\n\n",N[j].id,N[j].Name,N[j].Year_of_Experience);
		printf("==================================================================\n");
	}
	fclose(Nurses);

	Nurses = fopen("Nurses_Records.txt", "w");
	printf("Enter the index shown with the record of the nurse, whose record you want to delete : ");
	scanf("%d",&x);
	printf("\n");
	for(j=0; j<i; j++) {
		if(j==x) {
			continue;
		}
		fprintf(Nurses,"%d\n%s\n%d\n\n",N[j].id,N[j].Name,N[j].Year_of_Experience);
	}
	fclose(Nurses);
	printf("\t\t\tThe record has been DELETED.\n\n");
}

void nurses_modify_record() {
	system("cls");
	FILE *Nurses;
	Nurses=fopen("Nurses_Records.txt", "r");
	int i=0,j;
	while(!feof(Nurses)) {
		fscanf(Nurses,"%d\n%s\n%d\n\n",&N[i].id,&N[i].Name,&N[i].Year_of_Experience);
		i++;
	}
	for(j=0; j<i; j++) {
		printf("ID : %d\nName : %s\nExperience : %d years\n\n",N[j].id,N[j].Name,N[j].Year_of_Experience);
		printf("==================================================================\n");
	}
	fclose(Nurses);
	int id;
	printf("\n\nEnter the ID of Nurse whose record you want to modify : ");
	scanf("%d",&id);
	for(j=0; j<i; j++) {
		if(N[j].id==id) {
			break;
		}
	}
	if(j==i) {
		printf("\n\nThe ID you entered does not match with the ID of any nurse.\n\n");
	} else {
		int choice;
		int check;
		do {
			system("cls");
			printf("\n\nWhat thing you want to modify?\n\n");
			printf("1. ID\n2. Name\n3. Years of experience\n\n");
			printf("Enter the number associated with your choice : ");
			scanf("%d",&choice);
			switch(choice) {
				case 1: {
					printf("\nEnter NEW ID for Nurse : ");
					scanf("%d",&N[j].id);
					break;
				}
				case 2: {
					printf("\nEnter NEW Name for Nurse : ");
					scanf("%s",N[j].Name);
					break;
				}
				case 3: {
					printf("\nEnter NEW Years of Experience : ");
					scanf("%d",&N[j].Year_of_Experience);
					break;
				}
				default:
					printf("\nWrong input.");
			}
			printf("\n\n\tDo you want to modify any other thing of the same Nurse?\n\tIf yes then enter 1 and if no then enter any number other than 1 : ");
			scanf("%d",&check);
			printf("\n");
		} while(check==1);
		Nurses=fopen("Nurses_Records.txt", "w");
		for(j=0; j<i; j++) {
			fprintf(Nurses,"%d\n%s\n%d\n\n",N[j].id,N[j].Name,N[j].Year_of_Experience);
		}
		fclose(Nurses);
	}
}

void s_add_record() {
	system("cls");
	FILE *Sweepers;
	int c;
	int i;
	do {
		Sweepers = fopen("Sweepers_Records.txt", "a");
			printf("Enter ID : ");
			scanf("%d",&S[i].id);
			printf("Enter Name : ");
			scanf("%s",S[i].Name);
			printf("Enter Years Of Working : ");
			scanf("%d",&S[i].Years_OF_Work);
			fprintf(Sweepers,"%d\n%s\n%d\n\n",S[i].id,S[i].Name,S[i].Years_OF_Work);
		fclose(Sweepers);
		printf ("\n\tDo you want to add the record of any other sweeper?\n\tIf yes then enter 1 and if no then enter any number other than 1 : "); //asking user if the user wants to enter another record or not
		scanf ("%d",&c);
		printf("\n");
	} while(c==1);
}

void sweeper_view_record() {
	system("cls");
	FILE *Sweepers;
	int i=0,j;
	Sweepers=fopen("Sweepers_Records.txt", "r");
	printf("\t\t\tTHE LIST OF SWEEPERS:\n");
	printf("\t\t\t*********************\n");
	while(!feof(Sweepers)) {
		fscanf(Sweepers,"%d\n%s\n%d\n\n",&S[i].id,S[i].Name,&S[i].Years_OF_Work);
		i++;
	}
	for(j=0; j<i; j++) {
		printf("ID : %d\nName : %s\nExperience : %d years\n\n",S[j].id,S[j].Name,S[j].Years_OF_Work);
		printf("==================================================================\n");
	}
	fclose(Sweepers);
}

void sweeper_delete_record() {
	system("cls");
	FILE *Sweepers;
	int i=0,j,x;
	Sweepers=fopen("Sweepers_Records.txt", "r");
	printf("\t\t\tTHE LIST OF SWEEPERS:\n");
	printf("\t\t\t*********************\n");
	while(!feof(Sweepers)) {
		fscanf(Sweepers,"%d\n%s\n%d\n\n",&S[i].id,S[i].Name,&S[i].Years_OF_Work);
		i++;
	}
	for(j=0; j<i; j++) {
		printf("Index=%d\n",j);
		printf("ID : %d\nName : %s\nExperience : %d years\n\n",S[j].id,S[j].Name,S[j].Years_OF_Work);
		printf("==================================================================\n");
	}
	fclose(Sweepers);

	Sweepers = fopen("Sweepers_Records.txt", "w");
	printf("Enter the index shown with the record of the sweeper, whose record you want to delete : ");
	scanf("%d",&x);
	printf("\n");
	for(j=0; j<i; j++) {
		if(j==x) {
			continue;
		}
		fprintf(Sweepers,"%d\n%s\n%d\n\n",S[j].id,S[j].Name,S[j].Years_OF_Work);
	}
	fclose(Sweepers);
	printf("\t\t\tThe record has been DELETED.\n\n");
}

void sweeper_modify_record() {
	system("cls");
	FILE *Sweepers;
	Sweepers=fopen("Sweepers_Records.txt", "r");
	int i=0,j;
	while(!feof(Sweepers)) {
		fscanf(Sweepers,"%d\n%s\n%d\n\n",&S[i].id,S[i].Name,&S[i].Years_OF_Work);
		i++;
	}
	for(j=0; j<i; j++) {
		printf("ID : %d\nName : %s\nExperience : %d years\n\n",S[j].id,S[j].Name,S[j].Years_OF_Work);
		printf("==================================================================\n");
	}
	fclose(Sweepers);
	int id;
	printf("\n\nEnter the ID of Sweeper whose record you want to modify : ");
	scanf("%d",&id);
	for(j=0; j<i; j++) {
		if(S[j].id==id) {
			break;
		}
	}
	if(j==i) {
		printf("\n\nThe ID you entered does not match with the ID of any Sweeper.\n\n");
	} else {
		int choice;
		int check;
		do {
			system("cls");
			printf("\n\nWhat thing you want to modify?\n\n");
			printf("1. ID\n2. Name\n3. Year of experience\n\n");
			printf("Enter the number associated with your choice : ");
			scanf("%d",&choice);
			switch(choice) {
				case 1: {
					printf("\nEnter NEW ID for Sweeper : ");
					scanf("%d",&S[j].id);
					break;
				}
				case 2: {
					printf("\nEnter NEW Name for Sweeper : ");
					scanf("%s",S[j].Name);
					break;
				}
				case 3: {
					printf("\nEnter NEW Years of Working : ");
					scanf("%d",&S[j].Years_OF_Work);
					break;
				}
				default:
					printf("\nWrong input.");
			}
			printf("\n\n\tDo you want to modify any other thing of the same Sweeper?\n\tIf yes then enter 1 and if no then enter any number other than 1 : ");
			scanf("%d",&check);
			printf("\n");
		} while(check==1);
		Sweepers=fopen("Sweepers_Records.txt", "w");
		for(j=0; j<i; j++) {
			fprintf(Sweepers,"%d\n%s\n%d\n\n",S[j].id,S[j].Name,S[j].Years_OF_Work);
		}
		fclose(Sweepers);
	}
}

void hospital_Bill() {
	system("cls");
	FILE *patient;
	int i=0,j;
	patient = fopen("Patient_Records.txt", "r");
	while(!feof(patient)) {
		fscanf(patient,"%d\n%s\n%d\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n\n",&P[i].id,&P[i].Name,&P[i].age,&P[i].CNIC,&P[i].disease,&P[i].doa.day,&P[i].doa.month,&P[i].doa.year,&P[i].dod.day,&P[i].dod.month,&P[i].dod.year);
		i++;
	}
	fclose(patient);
	int ID;
	printf("Enter the ID of Patient : ");
	scanf("%d",&ID);
	printf("\n");
	for(j=0; j<i; j++) {
		if(ID==P[j].id) {
			int x=P[j].doa.day+(P[j].doa.month*30)+(P[j].doa.year*365);
			int y=P[j].dod.day+(P[j].dod.month*30)+(P[j].dod.year*365);
			printf("ID : %d\n\nNAME : %s\n\nAGE : %d\n\nCNIC : %s\n\nDISEASE : %s\n\nADMISSION DATE : %d-%d-%d\n\nDISCHARGED DATE : %d-%d-%d\n\n\n",P[j].id,P[j].Name,P[j].age,P[j].CNIC,P[j].disease,P[j].doa.day,P[j].doa.month,P[j].doa.year,P[j].dod.day,P[j].dod.month,P[j].dod.year);
			printf("Per Day Charges : 500\n\nYour Total Hospital Bill : %d\n\n\n",(y-x)*500);
			break;
		} 
	}
	if(j==i) {
	    printf("The ID which you entered, does not exist.\n\n\n");
	}
}

void discharched_Certificate()
{
	system("cls");
	FILE *patient;
	int i=0,j;
	patient = fopen("Patient_Records.txt", "r");
	while(!feof(patient)) {
		fscanf(patient,"%d\n%s\n%d\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n\n",&P[i].id,&P[i].Name,&P[i].age,&P[i].CNIC,&P[i].disease,&P[i].doa.day,&P[i].doa.month,&P[i].doa.year,&P[i].dod.day,&P[i].dod.month,&P[i].dod.year);
		i++;
	}
	fclose(patient);
	int ID;
	printf("Enter ID : ");
	scanf("%d",&ID);
	system("cls");
	for(j=0; j<i; j++) {
		if(ID==P[j].id) {
			printf("\t\t\t***************************************\n\t\t\t\tDischarged Certificate\n\t\t\t***************************************\n\n");
			printf("\t\tThis is Certified That\n\n\t\tPatient Name : %s\t\t\tHospital ID : %d\n\n\t\tAge : %d\t\t\t\tDisease : %s\n\n\t\tAdmission Date : %d-%d-%d\t\tDischarged Date : %d-%d-%d\n\n\t\tIs Discharged form IDC Hospital Abbottabad\n\n\n",P[j].Name,P[j].id,P[j].age,P[j].disease,P[j].doa.day,P[j].doa.month,P[j].doa.year,P[j].dod.day,P[j].dod.month,P[j].dod.year);
            break;
		} 
	}
	if(j==i)
	{
		printf("\nID does not Exist.\n\n\n");
	}
}