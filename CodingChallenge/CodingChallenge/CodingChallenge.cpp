#include <iostream>

class Observer{
	public : 
		char name[6] = {NULL};
};

class Employee : public Observer {
public:
	char role[6] = {NULL};
		
	void update(char state[10], char from[10]){
		std::cout << "\nName: ";
		std::cout << name;
		std::cout << "\nRole: ";
		std::cout << role;
		std::cout << "\nMachine Name: ";
		std::cout << from;
		std::cout << "\nNew State: ";
		std::cout << state;
	}
};

class Machine{
	public:
		char name[10];
};

class Subject : public Machine{
	public:
		char state[10];
		Employee attachedObservers[5];
		int i = 0;

		void setState(char s[10]) {
			strcpy_s(state, 10,s);
		}

		//changes from the initial design plan. I changed object attached from observer to employee otherwise i coulden't display role/use the update function
		void attach(Employee o) {
			attachedObservers[i] = o;
			i++;
		}

		void notifyAllObservers() {
			int x = 0;
			while (x < i){
				attachedObservers[x].update(state, name);
				x++;
			}
		}
};

int main(){
	Employee technician{};
	strcpy_s(technician.name, 6, "Steve");
	strcpy_s(technician.role, 6, "Techy");

	Subject machineOne;
	strcpy_s(machineOne.name, 10, "one");
	machineOne.setState((char*)"PRODUCING");
	Subject machineTwo;
	strcpy_s(machineTwo.name, 10, "two");
	machineTwo.setState((char*)"IDLE");
	Subject machineThree;
	strcpy_s(machineThree.name, 10, "three");
	machineThree.setState((char*)"STARVED");

	machineOne.attach(technician);
	machineTwo.attach(technician);
	machineThree.attach(technician);
	machineOne.notifyAllObservers();
	machineTwo.notifyAllObservers();
	machineThree.notifyAllObservers();
}