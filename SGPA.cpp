#include<iostream>
class StudentInformation{
    private:
        int studentID;
        float course[3];
        float cgpa;
    public:
        int ID(){
            return studentID;
        }
        float CGPA(){
            return cgpa;
        }
        void set_value(){
            std::cout<<"Enter the student ID : ";
            std::cin>>studentID;
            cgpa =0;
            for(int i=0;i<3;i++){
                std::cout<<"Enter the GPA for course "<<i+1<<" :";
                std::cin>>course[i];
                cgpa+= course[i];
            }
            cgpa/=3;
        }
};
class Results{
    private:
        StudentInformation obj[3];
        int pos[3];
    public:
        Results(StudentInformation a,StudentInformation b,StudentInformation c):obj{a,b,c}{
            if(obj[0].CGPA()>= obj[1].CGPA() && obj[1].CGPA() >=obj[2].CGPA()){
                pos[0]=1;
                pos[1]=2;
                pos[2]=3;
            }
            else if(obj[0].CGPA()>= obj[2].CGPA() && obj[2].CGPA()>=obj[1].CGPA()){
                pos[0]=1;
                pos[2]=2;
                pos[1]=3;
            }

            else if(obj[1].CGPA()>= obj[0].CGPA() && obj[0].CGPA()>=obj[2].CGPA()){
                pos[1]=1;
                pos[0]=2;
                pos[2]=3;
            }
            else if(obj[1].CGPA()>= obj[2].CGPA() && obj[2].CGPA()>=obj[0].CGPA()){
                pos[1]=1;
                pos[2]=2;
                pos[0]=3;
            }
             else if(obj[2].CGPA()>= obj[0].CGPA() && obj[0].CGPA()>=obj[1].CGPA()){
                pos[2]=1;
                pos[0]=2;
                pos[1]=3;
            }
            else{
                pos[2]=1;
                pos[1]=2;
                pos[0]=3;
            }
        }
        void finds(int id){
            for(int i=0;i<3;i++){
                if(id == obj[i].ID()){
                    std::cout<<"CGPA of Student ID "<<id<<" is "<<obj[i].CGPA()<<std::endl<<"Merit position: "<<pos[i]<<std::endl;
                }
            }
        }
};




int main()
{
    StudentInformation s1,s2,s3;
    s1.set_value();
    s2.set_value();
    s3.set_value();
    int roll;
    Results Rs(s1,s2,s3);
    std::cout<<"Enter Student ID to find :";
    std::cin>>roll;
    Rs.finds(roll);
    return 0;
}
