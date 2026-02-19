#include <algorithm>
#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;



// Abstract base class for all robots
class Robot {
protected:
    Robot* nextRobot; // Pointer to the next robot in the chain
    std::string task;

public:
    Robot() : nextRobot(nullptr) {}
    void setNextRobot(Robot* next) {
        nextRobot = next;
    }
    virtual void handleTask(const std::string& task) = 0; // Pure virtual function
    virtual ~Robot() = default;

    // Pure virtual function to get priority for sorting
    virtual int getPriority() const = 0;


   /* friend bool operator>(const Robot& lhs, const Robot& rhs) {
           return lhs.getPriority() > rhs.getPriority();
    }
    */
};

// Concrete robot classes
class WeldingRobot : public Robot {
public:
	void handleTask(const std::string& task) override {
    	this->task = task;
        if (task == "welding") {
            std::cout << "WeldingRobot: Handling welding task.\n";
        } else if (nextRobot) {
            nextRobot->handleTask(task);
        } else {
            std::cout << "WeldingRobot: Task not handled.\n";
        }
    }

    int getPriority() const override { return 4; } // Highest priority for sorting

    friend std::ostream& operator<<(std::ostream& output, const WeldingRobot& w){
    		output << "WeldingRobot receives task of [" << w.task << "]";
    		return output;
    }
};

class PaintingRobot : public Robot {
public:
    void handleTask(const std::string& task) override {
    	this->task = task;
        if (task == "painting") {
            std::cout << "PaintingRobot: Handling painting task.\n";
        } else if (nextRobot) {
            nextRobot->handleTask(task);
        } else {
            std::cout << "PaintingRobot: Task not handled.\n";
        }
    }

    int getPriority() const override { return 3; } // Medium priority

    friend std::ostream& operator<<(std::ostream& output, const PaintingRobot& p){
    	output << "PaintingRobot receives task of [" << p.task << "]";
        return output;
    }
};

class AssemblyRobot : public Robot {
public:
	void handleTask(const std::string& task) override {
		this->task = task;
		if (task == "assembly") {
			std::cout << "AssemblyRobot: Handling assembly task.\n";
		} else if (nextRobot) {
			nextRobot->handleTask(task);
		} else {
			std::cout << "AssemblyRobot: Task not handled.\n";
		}
	}

	int getPriority() const override { return 2; } // 2nd lowest for sorting

	friend std::ostream& operator<<(std::ostream& output, const AssemblyRobot& a){
		output << "AssemblyRobot receives task of [" << a.task << "]";
		return output;
	}
};

class InspectionRobot : public Robot {
public:
    void handleTask(const std::string& task) override {
    	this->task = task;
        if (task == "inspection") {
            std::cout << "InspectionRobot: Handling inspection task.\n";
        } else if (nextRobot) {
            nextRobot->handleTask(task);
        } else {
            std::cout << "InspectionRobot: Task not handled.\n";
        }
    }

    int getPriority() const override { return 1; } // Lowest priority

    friend std::ostream& operator<<(std::ostream& output, const InspectionRobot& i){
    	output << "InspectionRobot receives task of [" << i.task << "]";
    	return output;
     }
};


// Operator overloading to compare robots based on their task handling priority
bool operator>(const Robot& lhs, const Robot& rhs) {
    // For simplicity, assume WeldingRobot has the highest priority, then PaintingRobot, then InspectionRobot
    if (dynamic_cast<const WeldingRobot*>(&lhs)) return true;
    if (dynamic_cast<const PaintingRobot*>(&lhs) && dynamic_cast<const InspectionRobot*>(&rhs)) return true;
    return false;
}

// Comparison function for qsort
int robotComparator(const void* a, const void* b) {
    // Robot* lhs = *(Robot**)a;
    // Robot* rhs = *(Robot**)b;

	const Robot* const* lhs = static_cast<const Robot* const*> (a);
	const Robot* const* rhs = static_cast<const Robot* const*> (b);



	// return rhs->getPriority() - lhs->getPriority();
	return *lhs < *rhs;


}


void testChain(){
	// Create robots
	WeldingRobot weldingRobot;
	PaintingRobot paintingRobot;
	AssemblyRobot assemblyRobot;
	InspectionRobot inspectionRobot;

	// Set up the chain of responsibility
	weldingRobot.setNextRobot(&paintingRobot);
	paintingRobot.setNextRobot(&assemblyRobot);
	assemblyRobot.setNextRobot(&inspectionRobot);


	// Test the chain with different tasks
	std::string tasks[] = {"welding", "painting", "assembly", "inspection"};

	//range base for loop
	//how many times all the robots are invoked? 4*4=16?
	//limitation? Benefits?

	for (const auto& task : tasks) {
		weldingRobot.handleTask(task);
		std::cout << weldingRobot << std::endl;
	}
}


void testOperatorGreaterThan(){
	 	 // Create robots
		WeldingRobot weldingRobot;
		PaintingRobot paintingRobot;
		AssemblyRobot assemblyRobot;
		InspectionRobot inspectionRobot;

		// Demonstrate operator overloading
		if (weldingRobot > assemblyRobot) {
			        std::cout << "WeldingRobot has higher priority than AssemblyRobot.\n";
		} else {
			        std::cout << "AssemblyRobot has higher priority than WeldingRobot.\n";
		}
}


// Function to test sorting of robots
void testRobotSorting() {
    // Create robots and store pointers in a vector
    WeldingRobot weldingRobot, weldingRobot2;
    PaintingRobot paintingRobot, paintingRobot2;
	AssemblyRobot assemblyRobot, assemblyRobot2;
    InspectionRobot inspectionRobot, inspectionRobot2;

    // Create an array of pointers to robots
    Robot* robots[] = {&inspectionRobot,&weldingRobot2, &assemblyRobot2, &paintingRobot, &assemblyRobot, &inspectionRobot2, &weldingRobot, &paintingRobot2};
    const int size = std::size(robots);

    // Sort the robots using qsort
    qsort(robots, size, sizeof(Robot*), robotComparator);

    // Display sorted robots by priority
    std::cout << "Robots sorted by priority:\n";
	for (int i = 0; i < size; ++i) {
		robots[i]->handleTask("sorting"); // Example task to identify each robot
	}
}


void testFileOStreamUsingOperator(){
	    std::ofstream outputFile("robot.txt");
	    if (!outputFile) {
	        std::cerr << "Error opening file!" << std::endl;
	        exit(1);
	    }

	    WeldingRobot weldingRobot;
	    PaintingRobot paintingRobot;
		AssemblyRobot assemblyRobot;
	    InspectionRobot inspectionRobot;

	    outputFile << weldingRobot << "\n";
	    outputFile << paintingRobot << "\n";
		outputFile << assemblyRobot << "\n";
	    outputFile << inspectionRobot << "\n";

	    // Close the file
	    outputFile.close();
	    std::cout << "Data written to robot.txt" << std::endl;
}


int main() {

	std::cout << "Testing chain of responsibility:\n";
	testChain();

    std::cout << "\nTesting robot sorting:\n";
    testRobotSorting();

    std::cout << "\nTesting file stream output:\n";
    testFileOStreamUsingOperator();

	std::cout << "\nTesting operator Greater than\n";
	testOperatorGreaterThan();

    return 0;
}
