#include <iostream>
#include <vector>

using namespace std;


class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}
	
};


class Student :  public Person{
	private:
		vector<int> testScores;  
	public:
        /*	
        *   Class Constructor
        *   
        *   Parameters:
        *   firstName - A string denoting the Person's first name.
        *   lastName - A string denoting the Person's last name.
        *   id - An integer denoting the Person's ID number.
        *   scores - An array of integers denoting the Person's test scores.
        */
        // Write your constructor here
        Student(string firstName, string lastName, int identification, vector<int> score):Person(firstName, lastName, identification)
        {
            for(int i=0; i<score.size(); i++)
            {
                testScores.push_back(score[i]);
            }
            
        }

        /*	
        *   Function Name: calculate
        *   Return: A character denoting the grade.
        */
        // Write your function here
        char calculate()
        {
            int count=0;
            int n=0;
            for (int i=0; i<testScores.size(); i++)
            {
                count+=testScores[i];
                n++;
            }
            count=count/n;
            if (90<=count && count<=100)
            {
                return 'O';
            }
            if (80<=count && count<90)
            {
                return 'E';
            }
            if (70<=count && count<80)
            {
                return 'A';
            }
            if (55<=count && count<70)
            {
                return 'P';
            }
            if (40<=count && count<55)
            {
                return 'D';
            }
            else
            {
                return 'T';
            }
        }
};

int main() {