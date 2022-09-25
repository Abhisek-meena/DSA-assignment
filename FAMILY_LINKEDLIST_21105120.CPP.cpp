#include <bits/stdc++.h> // Name - Abhisek Meena
using namespace std;     // SID - 21105120   // Branch - ECE

// // *********************** To Make a Member Class for Making a Node for taking Name and Age **************************

class Member
{
public:
    string Member_name;
    int Member_Age;
    Member *Next_Member; // *********A node pointer for next node*************
    Member *Prev_Member; // *************A node pointer for previous node************
    Member(string Member_name, int Member_Age)
    {
        this->Member_name = Member_name;
        Next_Member = NULL;               // *************initialising next as NULL********************
        this->Member_Age = Member_Age;    
        Prev_Member = NULL;              // *************initialising prev as NULL********************
    }
};


// // ******************** To Add Family Member ************************

void Add_Family_Member(Member *&Family_head, string Member_name, int Member_Age)
{
    if (Family_head == NULL)
    {
        Family_head = new Member(Member_name, Member_Age);
        return;
    }
    Member *Temporary_Member = Family_head;
    while (Temporary_Member->Next_Member != NULL)
    {
        Temporary_Member = Temporary_Member->Next_Member;
    }
    Temporary_Member->Next_Member = new Member(Member_name, Member_Age);
    Temporary_Member->Next_Member->Prev_Member = Temporary_Member;
}

// *****************FUNCTION TO DISPLAY DATA AT START OF LINKED LIST*******************

void displayByFamily_Head(Member *Family_head)
{
    if (Family_head == NULL)
        return;
    Member *Temporary_Member = Family_head;
    while (Temporary_Member->Next_Member != NULL)
    {
        cout << "Name : " << Temporary_Member->Member_name << " , "
             << "Age : " << Temporary_Member->Member_Age << " <===>\n";
        Temporary_Member = Temporary_Member->Next_Member;
    }
    cout << "Name : " << Temporary_Member->Member_name << " , "
         << "Age : " << Temporary_Member->Member_Age;
}
    // ***************FUNCTION TO DISPLAY DATA FROM END OF LINKED LIST******************
void displayByFamily_junior(Member *Family_junior)
{
    if (Family_junior == NULL)
        return;
    Member *Temporary_Member = Family_junior;
    while (Temporary_Member->Prev_Member != NULL)
    {
        cout << "Name : " << Temporary_Member->Member_name << " , "
             << "Age : " << Temporary_Member->Member_Age << " <===>\n";
        Temporary_Member = Temporary_Member->Prev_Member;
    }
    cout << "Name : " << Temporary_Member->Member_name << " , "
         << "Age : " << Temporary_Member->Member_Age;
}

Member *Family_junior(Member *Family_head)
{
    Member *Temporary_Member = Family_head;
    while (Temporary_Member->Next_Member != NULL)
    {
        Temporary_Member = Temporary_Member->Next_Member;
    }
    return Temporary_Member;
}

int main()
{
    // ******************* Initialising an empty linked list *********************

    Member *Family_head = NULL;
    Add_Family_Member(Family_head,"GrandFather", 80);
    Add_Family_Member(Family_head, "GrandMother", 75);
    Add_Family_Member(Family_head, "Father", 55);
    Add_Family_Member(Family_head, "Mother", 53);
    Add_Family_Member(Family_head, "Brother", 25);
    Add_Family_Member(Family_head, "Me", 20);
     // ***************** Displaying Family details **********************
    cout << "Display From Family Head First\n"
         << endl;
    displayByFamily_Head(Family_head);
    cout << '\n'
         << endl
         << endl
         << endl;

    cout << "Display From Family Junior First\n"
         << endl;
    displayByFamily_junior(Family_junior(Family_head));

    return 0;
}

/*                                *************** BONUS QUESTION ********************

Q.Try to find a way to link the family members' doubly-linked list based on their relationship.
Ans.One way to link the family members doubly-linked list is by sorting the doubly linked list according to age in decending order.By doing so we will get a doubly linked list in which older generation people will be close to head in double linked list and new generation people will be close to tail in doubly linked list.
*/