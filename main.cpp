#include <iostream>

#include <iomanip>

#include <time.h>

#include <fstream>

using namespace std;

class quiz
{
    public:
        string question;
        string type;
        string choices[4];
        string choice;
        string answer;
        int question_id;
    private:
};

quiz quiz_2[50];
int random_array[50];
int random_array2[4];
int no_of_users=2,no_of_questions=6,no_of_mcq_questions=2,no_of_tf_questions=2,no_of_complete_questions=2,user_id,counter=0,counter2=0;
int mcq_score[10][1]={0};
int tf_score[10][1]={0};
int complete_score[10][1]={0};
int right_answers[10][20];
int x1[10][6];
int x2[10][6];
string ans1[10][6];
string ans2[10][6];
string type1[10][6];
string type2[10][6];
int current_score1[10][6];
int current_score2[10][6];

//initializing questions//

void question_list()
{
    quiz_2[0].question="Electrons are larger than molecules";
    quiz_2[0].type="TF";
    quiz_2[0].choice="false";
    quiz_2[0].question_id=1;
    quiz_2[1].question="Brazil is the only country in the Americas whose official language is Portuguese";
    quiz_2[1].type="TF";
    quiz_2[1].choice="true";
    quiz_2[1].question_id=2;
    quiz_2[2].question="... is at the center of our Solar System";
    quiz_2[2].type="COMPLETE";
    quiz_2[2].answer="Sun";
    quiz_2[2].question_id=3;
    quiz_2[3].question="... is used to recover copper from copper sulphate solution";
    quiz_2[3].type="COMPLETE";
    quiz_2[3].answer="Fe";
    quiz_2[3].question_id=4;
    quiz_2[4].question="'OS' computer abbreviation usually means?";
    quiz_2[4].type="MCQ";
    quiz_2[4].choices[0]="Operating System";
    quiz_2[4].choices[1]="Open Software";
    quiz_2[4].choices[2]="Order of Significance";
    quiz_2[4].choices[3]="Optical Sensor";
    quiz_2[4].question_id=5;
    quiz_2[5].question="What is the relationship between resistance and conductivity?";
    quiz_2[5].type="MCQ";
    quiz_2[5].choices[0]="R=1/S";
    quiz_2[5].choices[1]="R=S";
    quiz_2[5].choices[2]="R=S*S";
    quiz_2[5].choices[3]="R is not related to S";
    quiz_2[5].question_id=6;
}

class user
{
    public:
        string first_name[30];
        string last_name[30];
        string username[30];
        string password[30];
        string type[30];

        //initializing users//

        user()
        {
            first_name[0]="user1";
            last_name[0]="user1";
            username[0]="user1";
            password[0]="user1";
            type[0]="player";
            first_name[1]="user2";
            last_name[1]="user2";
            username[1]="user2";
            password[1]="user2";
            type[1]="admin";
        }
    private:
};

class player : public user
{
    public:
        int scores[30][20];
        int no_of_quizzes[20];
        player()
        {           //initializing scores and number of quizzes for each user//
            for(int i=0;i<50;i++)
            {
                for(int j=0;j<30;j++)
                    scores[i][j]=0;
            }
            for(int k=0;k<20;k++)
                no_of_quizzes[k]=0;
        }
        void player_menu()
        {
            cout<<"-----------------------------"<<endl;
            cout<<"Welcome "<<first_name[user_id]<<" "<<last_name[user_id]<<" (player), please choose from the following options"<<endl;
            cout<<"[1] Switch accounts"<<endl;
            cout<<"[2] Update your name"<<endl;
            cout<<"[3] Start a new quiz"<<endl;
            cout<<"[4] Display your scores statistics"<<endl;
            cout<<"[5] Display all your scores"<<endl;
            cout<<"[6] Display details of your last two quizzes"<<endl;
            cout<<"[7] Exit the program"<<endl;
            cout<<"-----------------------------"<<endl;
            cout<<"My choice: ";
        }


        void random(int random_array[],int num)
        {
            int arr[num];
            bool check;
            int i=0;
            srand(time(0));
            while(i!=num)
            {
                arr[i]=rand()%num;
                check=true;
                for(int j=0;j<num;j++)
                {
                    if(i==j)
                        continue;
                    else if(arr[j]==arr[i])
                    {
                        check=false;
                        break;
                    }
                }
                if(check)
                {        random_array[i]=arr[i];
                    i++;
                }
            }
        }

        void start()
        {
            int n=0,counter_1=0,counter_2=0,counter_3=0,m=0;
            string ans;
            random(random_array,no_of_questions);

            //making sure that there is 2 questions of each type in the quiz//

            while (counter_1+counter_2+counter_3!=6)
            {
                for(int p=0;p<6;p++)
                {
                    if(quiz_2[random_array[p]].type=="MCQ")
                        counter_1++;
                    else if(quiz_2[random_array[p]].type=="TF")
                        counter_2++;
                    else if(quiz_2[random_array[p]].type=="COMPLETE")
                        counter_3++;
                    if(counter_1>2 || counter_2>2 || counter_3>2)
                {
                    random(random_array,no_of_questions);
                    counter_1=0,counter_2=0,counter_3=0;
                    break;
                }
                }
                //cout<<counter_1<<" "<<counter_2<<" "<<counter_3<<endl;//
            }
            for(int i=0;i<6;i++)
            {
                cout<<i+1<<"- "<<quiz_2[random_array[i]].question<<endl;
                if(quiz_2[random_array[i]].type=="MCQ")
                {
                    for(int j=0;j<4;j++)
                    {
                        random(random_array2,4);
                        switch(j)
                        {
                            case 0:
                                cout<<"[a] "<<quiz_2[random_array[i]].choices[random_array2[j]]<<"\t";
                                break;
                            case 1:
                                cout<<"[b] "<<quiz_2[random_array[i]].choices[random_array2[j]]<<"\t";
                                break;
                            case 2:
                                cout<<"[c] "<<quiz_2[random_array[i]].choices[random_array2[j]]<<"\t";
                                break;
                            case 3:
                                cout<<"[d] "<<quiz_2[random_array[i]].choices[random_array2[j]]<<"\t";
                                break;
                        }
                    }
                    cout<<endl;
                    getline(cin,ans);
                    if(ans!="a" & ans!="b" & ans!="c" & ans!="d")
                    {
                        cout<<"-----------------------"<<endl;
                        cout<<"invalid input"<<endl;
                        cout<<"-----------------------"<<endl;
                        i--;
                    }
                    else
                    {
                        if(ans=="a")
                        {
                            if(quiz_2[random_array[i]].choices[random_array2[0]]==quiz_2[random_array[i]].choices[0])
                            {
                                right_answers[user_id][no_of_quizzes[user_id]]+=1;
                                scores[user_id][no_of_quizzes[user_id]]+=2;
                                mcq_score[user_id][0]+=2;
                            }
                        }
                        else if(ans=="b")
                        {
                            if(quiz_2[random_array[i]].choices[random_array2[1]]==quiz_2[random_array[i]].choices[0])
                            {
                                right_answers[user_id][no_of_quizzes[user_id]]+=1;
                                scores[user_id][no_of_quizzes[user_id]]+=2;
                                mcq_score[user_id][0]+=2;
                            }
                        }
                        else if(ans=="c")
                        {
                            if(quiz_2[random_array[i]].choices[random_array2[2]]==quiz_2[random_array[i]].choices[0])
                            {
                                right_answers[user_id][no_of_quizzes[user_id]]+=1;
                                scores[user_id][no_of_quizzes[user_id]]+=2;
                                mcq_score[user_id][0]+=2;
                            }
                        }
                        else if(ans=="d")
                        {
                            if(quiz_2[random_array[i]].choices[random_array2[3]]==quiz_2[random_array[i]].choices[0])
                            {
                                right_answers[user_id][no_of_quizzes[user_id]]+=1;
                                scores[user_id][no_of_quizzes[user_id]]+=2;
                                mcq_score[user_id][0]+=2;
                            }
                        }
                    }
                }
                else if(quiz_2[random_array[i]].type=="TF")
                {
                    getline(cin,ans);
                    if(ans!="true" & ans!="false")
                    {
                        cout<<"-----------------------"<<endl;
                        cout<<"invalid input"<<endl;
                        cout<<"-----------------------"<<endl;
                        i--;
                    }
                    else
                    {
                        if(ans==quiz_2[random_array[i]].choice)
                        {
                            right_answers[user_id][no_of_quizzes[user_id]]+=1;
                            scores[user_id][no_of_quizzes[user_id]]+=1;
                            tf_score[user_id][0]+=1;
                        }
                    }
                }
            else if(quiz_2[random_array[i]].type=="COMPLETE")
            {
                getline(cin,ans);
                if(ans==quiz_2[random_array[i]].answer)
                {
                    right_answers[user_id][no_of_quizzes[user_id]]+=1;
                    scores[user_id][no_of_quizzes[user_id]]+=3;
                    complete_score[user_id][0]+=3;
                }
            }
            if(counter2==2)
                counter2=0;
            if(counter2==0)
                current_score1[user_id][m]=scores[user_id][no_of_quizzes[user_id]];
            else if(counter2==1)
                current_score2[user_id][m]=scores[user_id][no_of_quizzes[user_id]];
            m++;

//            storing mcq answers

            if(quiz_2[random_array[i]].type=="MCQ")
            {
                if(counter2==0)
                {
                    if(ans=="a")
                        ans1[user_id][n]=quiz_2[random_array[i]].choices[random_array2[0]];
                    else if(ans=="b")
                        ans1[user_id][n]=quiz_2[random_array[i]].choices[random_array2[1]];
                    else if(ans=="c")
                        ans1[user_id][n]=quiz_2[random_array[i]].choices[random_array2[2]];
                    else if(ans=="d")
                        ans1[user_id][n]=quiz_2[random_array[i]].choices[random_array2[3]];
                    n++;
                }
                else if(counter2==1)
                {
                    if(ans=="a")
                        ans2[user_id][n]=quiz_2[random_array[i]].choices[random_array2[0]];
                    else if(ans=="b")
                        ans2[user_id][n]=quiz_2[random_array[i]].choices[random_array2[1]];
                    else if(ans=="c")
                        ans2[user_id][n]=quiz_2[random_array[i]].choices[random_array2[2]];
                    else if(ans=="d")
                        ans2[user_id][n]=quiz_2[random_array[i]].choices[random_array2[3]];
                    n++;
                }
            }

            //storing tf and complete answers//

            else
            {
                if(counter2==0)
                {
                    ans1[user_id][n]=ans;
                    n++;
                }
                else if(counter2==1)
                {
                    ans2[user_id][n]=ans;
                    n++;
                }
            }
        }
        counter2++;
        if(counter==2)
            counter=0;
        if(counter==0)
        {
            int y=0;
            for(int k=0;k<6;k++)
            {
                x1[user_id][k]=random_array[y];
                type1[user_id][k]=quiz_2[random_array[y]].type;
                y++;
            }
        }
        else if(counter==1)
        {
            int m=0;
            for(int l=0;l<6;l++)
            {
                x2[user_id][l]=random_array[m];
                type2[user_id][l]=quiz_2[random_array[m]].type;
                m++;
            }
        }
        counter++;
        no_of_quizzes[user_id]+=1;
     }

    void scores_stats()
    {
        int highest_score=0,lowest_score=12;
        float average_score,sum=0;
        float average_mcq,average_tf,average_complete;
        for(int i=0;i<no_of_quizzes[user_id];i++)
        {
            if (scores[user_id][i]>highest_score)
                highest_score=scores[user_id][i];
            if (scores[user_id][i]<lowest_score)
                lowest_score=scores[user_id][i];
            sum+=float(scores[user_id][i]);
        }
        average_score=sum/float(no_of_quizzes[user_id]);
        cout<<"Your score statistics per quiz:"<<endl;
        cout<<"\t- Number of Quizzes taken: "<<no_of_quizzes[user_id]<<endl;
        cout<<"\t- Highest score: "<<highest_score<<'/'<<12<<endl;
        cout<<"\t- Lowest score: "<<lowest_score<<'/'<<12<<endl;
        cout<<"\t- Average score: "<<fixed<<setprecision(1)<<average_score<<'/'<<12<<endl;
        cout<<"Your score statistics per question type:"<<endl;
        cout<<"\t- Number of MCQ questions: "<<no_of_mcq_questions<<endl;
        cout<<"\t- Number of T/F questions: "<<no_of_tf_questions<<endl;
        cout<<"\t- Number of Complete questions: "<<no_of_complete_questions<<endl;
        average_mcq=float(mcq_score[user_id][0])/float(2*no_of_quizzes[user_id]);
        average_tf=float(tf_score[user_id][0])/float(2*no_of_quizzes[user_id]);
        average_complete=float(complete_score[user_id][0])/float(2*no_of_quizzes[user_id]);
        cout<<"\t- Average score of MCQ questions: "<<fixed<<setprecision(1)<<average_mcq<<'/'<<2<<endl;
        cout<<"\t- Average score of T/F questions: "<<fixed<<setprecision(1)<<average_tf<<'/'<<1<<endl;
        cout<<"\t- Average score of Complete questions: "<<fixed<<setprecision(1)<<average_complete<<'/'<<3<<endl;
    }

    void details_of_last_quizzes()
    {
        cout<<"---------------------------"<<endl;
        cout<<"Quiz no."<<no_of_quizzes[user_id]-1<<endl;
        cout<<"---------------------------"<<endl;
        for(int i=0;i<6;i++)
        {
            cout<<i+1<<"- "<<quiz_2[x1[user_id][i]].question<<endl<<endl;
            if(type1[user_id][i]=="MCQ")
            {
                if(ans1[user_id][i]==quiz_2[x1[user_id][i]].choices[0])
                    cout<<"Your answer was: "<<ans1[user_id][i]<<"\t and it was correct"<<endl<<endl;
                else
                    cout<<"Your answer was: "<<ans1[user_id][i]<<"\tCorrect answer is: "<<quiz_2[x1[user_id][i]].choices[0]<<endl<<endl;
                if(i==0)
                    cout<<"Your score in this question: "<<current_score1[user_id][i]<<"/2"<<endl<<endl;
                else
                    cout<<"Your score in this question: "<<current_score1[user_id][i]-current_score1[user_id][i-1]<<"/2"<<endl<<endl;
            }
            else if(type1[user_id][i]=="TF")
            {
                if(ans1[user_id][i]==quiz_2[x1[user_id][i]].choice)
                    cout<<"Your answer was: "<<ans1[user_id][i]<<"\t and it was correct"<<endl<<endl;
                else
                    cout<<"Your answer was: "<<ans1[user_id][i]<<"\tCorrect answer is: "<<quiz_2[x1[user_id][i]].choice<<endl<<endl;
                if(i==0)
                    cout<<"Your score in this question: "<<current_score1[user_id][i]<<"/1"<<endl<<endl;
                else
                    cout<<"Your score in this question: "<<current_score1[user_id][i]-current_score1[user_id][i-1]<<"/1"<<endl<<endl;
            }
            else if(type1[user_id][i]=="COMPLETE")
            {

                if(ans1[user_id][i]==quiz_2[x1[user_id][i]].answer)
                    cout<<"Your answer was: "<<ans1[user_id][i]<<"\t and it was correct"<<endl<<endl;
                else
                    cout<<"Your answer was: "<<ans1[user_id][i]<<"\tCorrect answer is: "<<quiz_2[x1[user_id][i]].answer<<endl<<endl;
                if(i==0)
                    cout<<"Your score in this question: "<<current_score1[user_id][i]<<"/3"<<endl<<endl;
                else
                    cout<<"Your score in this question: "<<current_score1[user_id][i]-current_score1[user_id][i-1]<<"/3"<<endl<<endl;
            }
            cout<<"Your current score: "<<current_score1[user_id][i]<<"/12"<<endl<<endl;
        }
        cout<<"---------------------------"<<endl;
        cout<<"Your total score: "<<scores[user_id][no_of_quizzes[user_id]-2]<<"/12"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<"Quiz no."<<no_of_quizzes[user_id]<<endl;
        cout<<"---------------------------"<<endl;
        for(int j=0;j<6;j++)
        {
            cout<<j+1<<"- "<<quiz_2[x2[user_id][j]].question<<endl<<endl;
            if(type2[user_id][j]=="MCQ")
            {
                if(ans2[user_id][j]==quiz_2[x2[user_id][j]].choices[0])
                    cout<<"Your answer was: "<<ans2[user_id][j]<<"\t and it was correct"<<endl<<endl;
                else
                    cout<<"Your answer was: "<<ans2[user_id][j]<<"\tCorrect answer is: "<<quiz_2[x2[user_id][j]].choices[0]<<endl<<endl;
                if(j==0)
                    cout<<"Your score in this question: "<<current_score2[user_id][j]<<"/2"<<endl<<endl;
                else
                    cout<<"Your score in this question: "<<current_score2[user_id][j]-current_score2[user_id][j-1]<<"/2"<<endl<<endl;
            }
            else if(type2[user_id][j]=="TF")
            {
                if(ans2[user_id][j]==quiz_2[x2[user_id][j]].choice)
                    cout<<"Your answer was: "<<ans2[user_id][j]<<"\t and it was correct"<<endl<<endl;
                else
                    cout<<"Your answer was: "<<ans2[user_id][j]<<"\tCorrect answer is: "<<quiz_2[x2[user_id][j]].choice<<endl<<endl;
                if(j==0)
                    cout<<"Your score in this question: "<<current_score2[user_id][j]<<"/1"<<endl<<endl;
                else
                    cout<<"Your score in this question: "<<current_score2[user_id][j]-current_score2[user_id][j-1]<<"/1"<<endl<<endl;
            }
            else if(type2[user_id][j]=="COMPLETE")
            {
                if(ans2[user_id][j]==quiz_2[x2[user_id][j]].answer)
                    cout<<"Your answer was: "<<ans2[user_id][j]<<"\t and it was correct"<<endl<<endl;
                else
                    cout<<"Your answer was: "<<ans2[user_id][j]<<"\tCorrect answer is: "<<quiz_2[x2[user_id][j]].answer<<endl<<endl;
                if(j==0)
                    cout<<"Your score in this question: "<<current_score2[user_id][j]<<"/3"<<endl<<endl;
                else
                    cout<<"Your score in this question: "<<current_score2[user_id][j]-current_score2[user_id][j-1]<<"/3"<<endl<<endl;
            }
            cout<<"Your current score: "<<current_score2[user_id][j]<<"/12"<<endl<<endl;
        }
        cout<<"---------------------------"<<endl;
        cout<<"Your score: "<<scores[user_id][no_of_quizzes[user_id]-1]<<"/12"<<endl;
        cout<<"---------------------------"<<endl;
    }
};

class admin : public user
{
    public:
        void admin_menu()
        {
            cout<<"-----------------------------"<<endl;
            cout<<"Welcome "<<first_name[user_id]<<" "<<last_name[user_id]<<" (admin), please choose from the following options"<<endl;
            cout<<"[1] Switch accounts"<<endl;
            cout<<"[2] Update your name"<<endl;
            cout<<"[3] View all users"<<endl;
            cout<<"[4] Add new users"<<endl;
            cout<<"[5] View all questions"<<endl;
            cout<<"[6] Add new questions"<<endl;
            cout<<"[7] Load questions from file"<<endl;
            cout<<"[8] Exit the program"<<endl;
            cout<<"-----------------------------"<<endl;
            cout<<"My choice: ";
        }

        void view_questions()
        {
            int r1=1,r2=1,r3=1;
            cout<<"Number of questions available: "<<no_of_questions<<endl;
            cout<<"--------------------------------"<<endl;
            cout<<"MCQ Questions list("<<"Total: "<<no_of_mcq_questions<<" Questions)"<<endl;
            cout<<"--------------------------------"<<endl;
            for(int i=0;i<no_of_questions;i++)
            {
                if(quiz_2[i].type=="MCQ")
                {
                    cout<<'['<<r1<<']'<<"(ID: "<<quiz_2[i].question_id<<") "<<quiz_2[i].question<<endl;
                    r1++;
                    for(int j=0;j<4;j++)
                    {
                        switch(j)
                        {
                            case 0:
                                cout<<"*[a] "<<quiz_2[i].choices[0]<<"\t";
                                break;
                            case 1:
                                cout<<"[b] "<<quiz_2[i].choices[1]<<"\t";
                                break;
                            case 2:
                                cout<<"[c] "<<quiz_2[i].choices[2]<<"\t";
                                break;
                            case 3:
                                cout<<"[d] "<<quiz_2[i].choices[3]<<"\t";
                                break;
                        }
                        cout<<endl<<endl;
                    }
                }
            }
            cout<<"COMPLETE Questions list("<<"Total: "<<no_of_complete_questions<<" Questions)"<<endl;
            cout<<"--------------------------------"<<endl;
            for(int i=0;i<no_of_questions;i++)
            {
                if(quiz_2[i].type=="COMPLETE")
                {
                    cout<<'['<<r2<<']'<<"(ID: "<<quiz_2[i].question_id<<") "<<quiz_2[i].question<<endl;
                    r2++;
                    cout<<"Answer: "<<quiz_2[i].answer<<endl<<endl;
                }
            }
            cout<<"T/F Questions list("<<"Total: "<<no_of_tf_questions<<" Questions)"<<endl;
            cout<<"--------------------------------"<<endl;
            for(int i=0;i<no_of_questions;i++)
            {
                if(quiz_2[i].type=="TF")
                {
                    cout<<'['<<r3<<']'<<"(ID: "<<quiz_2[i].question_id<<") "<<quiz_2[i].question<<endl;
                    r3++;
                    cout<<"Answer: "<<quiz_2[i].choice<<endl<<endl;
                }
            }
        }

        void slicing(string& str,int start)
        {
            string str2="000";
            int y=0;
            for(int i=start;i<=str.length();i++)
            {
                str2[y]=str[i];
                y+=1;
            }
            str=str2;
        }
};

bool login(player,admin);

bool sign_up(player&,admin&,string);

int main()
{
    int counter3=0,counter4=0,player_ans,admin_ans,num,num2,no_of_questions_in_file=0,questions_counter=0,choices_counter=0;
    user users;
    player players;
    admin admins;
    bool check,check2,check3=false,check4=false;
    string ans,ans2,ans3,user_type,file_name,word,word2;
    fstream infile;
    question_list();
    cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\tWelcome to the Quiz game program V2.0!"<<endl;
    cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
    while(1)
    {
        player_ans=0,admin_ans=0;
        if(counter3==0)
            check=login(players,admins);
        if(check)
        {
            if(players.type[user_id]=="player")
            {
                players.player_menu();
                cin>>player_ans;
                cin.clear();
                cin.ignore(10000,'\n');
                switch(player_ans)
                {
                    case 1:
                        system("CLS");
                        break;
                    case 2:
                        system("CLS");
                        cout<<"Enter your first name"<<endl;
                        getline(cin,players.first_name[user_id]);
                        cout<<"Enter your last name"<<endl;
                        getline(cin,players.last_name[user_id]);
                        break;
                    case 3:
                        if(no_of_questions<6)
                        {
                            cout<<"There are not enough questions for the quiz, you should add more questions"<<endl;
                            break;
                        }
                        if(no_of_mcq_questions<2 || no_of_tf_questions<2 || no_of_complete_questions<2)
                        {
                            cout<<"Each type of questions must be at least 2"<<endl;
                            break;
                        }
                        system("CLS");
                        players.start();
                        cout<<"---------------------"<<endl;
                        cout<<"You have finished the quiz"<<endl;
                        cout<<"Right answers: "<<right_answers[user_id][players.no_of_quizzes[user_id]-1]<<endl;
                        cout<<"Wrong answers: "<<6-right_answers[user_id][players.no_of_quizzes[user_id]-1]<<endl;
                        cout<<"Your score is: "<<players.scores[user_id][players.no_of_quizzes[user_id]-1]<<'/'<<12<<endl;
                        cout<<"---------------------"<<endl;
                        break;
                    case 4:
                        if (players.no_of_quizzes[user_id]==0)
                        {
                            cout<<"-----------------------"<<endl;
                            cout<<"You should take the quiz first"<<endl;
                            cout<<"-----------------------"<<endl;
                            break;
                        }
                        system("CLS");
                        players.scores_stats();
                        cout<<endl<<"Press [b] if you want to go back to the main menu or [e] to exit"<<endl;
                        cout<<"My choice: ";
                        getline(cin,ans2);
                        if(ans2!="b" and ans2!="e")
                        {
                            cout<<"-----------------------"<<endl;
                            cout<<"invalid input"<<endl;
                            cout<<"-----------------------"<<endl;
                        }
                        break;
                    case 5:
                        if (players.no_of_quizzes[user_id]==0)
                        {
                            cout<<"-----------------------"<<endl;
                            cout<<"You should take the quiz first"<<endl;
                            cout<<"-----------------------"<<endl;
                            break;
                        }
                        system("CLS");
                        cout<<"- Number of Quizzes taken: "<<players.no_of_quizzes[user_id]<<endl;
                        for(int i=0;i<players.no_of_quizzes[user_id];i++)
                        {
                            cout<<"-----------------"<<endl;
                            cout<<"Quiz "<<i+1<<endl;
                            cout<<"Right answers:\t"<<players.scores[user_id][i]<<endl;
                            cout<<"Wrong answers:\t"<<6-players.scores[user_id][i]<<endl;
                            cout<<"Score:\t"<<players.scores[user_id][i]<<'/'<<12<<endl;
                            cout<<"-----------------"<<endl;
                        }
                        break;
                    case 6:
                        if (players.no_of_quizzes[user_id]<2)
                        {
                            cout<<"-----------------------"<<endl;
                            cout<<"You have to take at least two quizzes first"<<endl;
                            cout<<"-----------------------"<<endl;
                            break;
                        }
                        system("CLS");
                        players.details_of_last_quizzes();
                        break;
                    case 7:
                        break;
                    default:
                        cout<<"-----------------------"<<endl;
                        cout<<"Invalid input"<<endl;
                        cout<<"-----------------------"<<endl;
                        break;
                }
            }
            else if(admins.type[user_id]=="admin")
            {
                admins.admin_menu();
                cin>>admin_ans;
                cin.clear();
                cin.ignore(10000,'\n');
                switch(admin_ans)
                {
                    case 1:
                        system("CLS");
                        break;
                    case 2:
                        system("CLS");
                        cout<<"Enter your first name"<<endl;
                        getline(cin,admins.first_name[user_id]);
                        cout<<"Enter your last name"<<endl;
                        getline(cin,admins.last_name[user_id]);
                        break;
                    case 3:
                        system("CLS");
                        cout<<"-------------------------------------------------------"<<endl;
                        cout<<"First name\t"<<"Last name\t"<<"Username\t"<<"Role"<<endl;
                        for(int i=0;i<no_of_users;i++)
                        {
                            if(admins.type[i]=="admin")
                                cout<<admins.first_name[i]<<"\t\t"<<admins.last_name[i]<<"\t\t"<<admins.username[i]<<"\t\t"<<admins.type[i]<<endl<<endl;
                            else if(players.type[i]=="player")
                                cout<<players.first_name[i]<<"\t\t"<<players.last_name[i]<<"\t\t"<<players.username[i]<<"\t\t"<<players.type[i]<<endl<<endl;
                        }
                        cout<<"-------------------------------------------------------"<<endl;
                        cout<<"Press [n] if you want to add a new user or [b] if you want to exit"<<endl;
                        cin>>ans3;
                        if(ans3!="b" & ans3!="n")
                        {
                            cout<<"-----------------------"<<endl;
                            cout<<"invalid input"<<endl;
                            cout<<"-----------------------"<<endl;
                            break;
                        }
                        else if(ans3=="b")
                            break;
                    case 4:
                        system("CLS");
                        cout<<"What type of user will you be? ";
                        cin>>user_type;
                        while(user_type!="player" and user_type!="admin")
                        {
                            cout<<"invalid user type please enter it again"<<endl;
                            cin>>user_type;
                        }

//                        making sure that the entered user name is unique

                        check2=sign_up(players,admins,user_type);
                        while(check2==false)
                            check2=sign_up(players,admins,user_type);
                        no_of_users++;
                        break;
                    case 5:
                        system("CLS");
                        admins.view_questions();
                        cout<<"-----------------------------------------------------------------------"<<endl;
                        cout<<"Press [e] and the question ID if you want to delete a question (Example: e 2)"<<endl;
                        cout<<"Press [f] if you want to go back to the main menu"<<endl;
                        getline(cin,ans);

//                        here i take the input of the user as a string then i make sure that the first two characters is e and ' '
//                        then i check if there are any letters after that, when i done checking and make sure that all the characters
//                        left are numbers, i remove the e and ' ' characters and leave the numbers which i then convert them into int
//                        instead of being string

                        if (ans[0]=='e' & ans[1]==' ')
                        {
                            for(int w=2;w<ans.length();w++)
                            {
                                if(isalpha(ans[w]))
                                {
                                    check3=true;
                                    break;
                                }
                            }
                            if(check3)
                            {
                                cout<<"-----------------------"<<endl;
                                cout<<"invalid input"<<endl;
                                cout<<"-----------------------"<<endl;
                                break;
                            }
                            else
                                admins.slicing(ans,2);
                            num=stoi(ans);
                            if(num>no_of_questions || num<=0)
                            {
                                cout<<"-----------------------"<<endl;
                                cout<<"invalid input"<<endl;
                                cout<<"-----------------------"<<endl;
                                break;
                            }
                            if(quiz_2[num-1].type=="MCQ")
                                no_of_mcq_questions--;
                            else if(quiz_2[num-1].type=="TF")
                                no_of_tf_questions--;
                            else if(quiz_2[num-1].type=="COMPLETE")
                                no_of_complete_questions--;
                            for(int j=num-1;j<no_of_questions;j++)
                            {
                                quiz_2[j].question=quiz_2[j+1].question;
                                if(quiz_2[j+1].type=="MCQ")
                                {
                                    for(int m=0;m<4;m++)
                                        quiz_2[j].choices[m]=quiz_2[j+1].choices[m];
                                }
                                else if(quiz_2[j+1].type=="TF")
                                    quiz_2[j].choice=quiz_2[j+1].choice;
                                else if(quiz_2[j+1].type=="COMPLETE")
                                    quiz_2[j].answer=quiz_2[j+1].answer;
                                quiz_2[j].type=quiz_2[j+1].type;
                            }
                            no_of_questions-=1;
                            system("CLS");
                            admins.view_questions();
                        }
                        else if (ans=="f")
                            break;
                        else
                        {
                            cout<<"-----------------------"<<endl;
                            cout<<"invalid input"<<endl;
                            cout<<"-----------------------"<<endl;
                        }
                        break;
                    case 6:
                        system("CLS");
                        cout<<"How many questions would you like to add ?"<<endl;
                        cin>>num2;
                        if(num2<=0)
                        {
                            cout<<"-----------------------"<<endl;
                            cout<<"invalid input"<<endl;
                            cout<<"-----------------------"<<endl;
                            cin.clear();
                            cin.ignore(10000,'\n');
                            break;
                        }
                        cin.ignore(10000,'\n');

//                        checking if there is a duplicate question being added

                        for(int i=0;i<num2;i++)
                        {
                            cout<<"What is the type of question would you like to add ?"<<endl;
                            cin>>quiz_2[no_of_questions+i].type;
                            while(quiz_2[no_of_questions+i].type!="MCQ" & quiz_2[no_of_questions+i].type!="TF" & quiz_2[no_of_questions+i].type!="COMPLETE")
                            {
                                cout<<"-----------------------"<<endl;
                                cout<<"invalid input enter it again "<<endl;
                                cout<<"-----------------------"<<endl;
                                cin>>quiz_2[no_of_questions+i].type;
                            }
                            cin.ignore(10000,'\n');
                            cout<<"Enter the question"<<endl;
                            getline(cin,quiz_2[no_of_questions+i].question);
                            for(int j=0;j<no_of_questions+num2;j++)
                            {
                                while(quiz_2[i+no_of_questions].question==quiz_2[j].question)
                                {
                                    cout<<"------------------------------------"<<endl;
                                    cout<<"The question is duplicated ....... Enter a unique one"<<endl;
                                    cout<<"-----------------------------------"<<endl;
                                    getline(cin,quiz_2[no_of_questions+i].question);
                                }
                            }
                            if(quiz_2[no_of_questions+i].type=="MCQ")
                            {
                                no_of_mcq_questions++;
                                cout<<"Enter the choices"<<endl;
                                for(int n=0;n<4;n++)
                                    getline(cin,quiz_2[no_of_questions+i].choices[n]);
                            }
                            else if(quiz_2[no_of_questions+i].type=="TF")
                            {
                                no_of_tf_questions++;
                                cout<<"Enter the choice"<<endl;
                                getline(cin,quiz_2[no_of_questions+i].choice);
                                while(quiz_2[no_of_questions+i].choice!="true" & quiz_2[no_of_questions+i].choice!="false")
                                {
                                    cout<<"----------------------------------"<<endl;
                                    cout<<"invalid input....please enter true or false"<<endl;
                                    cout<<"----------------------------------"<<endl;
                                    getline(cin,quiz_2[no_of_questions+i].choice);
                                }
                            }
                            else if(quiz_2[no_of_questions+i].type=="COMPLETE")
                            {
                                no_of_complete_questions++;
                                cout<<"Enter the answer"<<endl;
                                getline(cin,quiz_2[no_of_questions+i].answer);
                            }
                            quiz_2[no_of_questions+i].question_id=no_of_questions+i+1;
                        }
                        no_of_questions+=num2;
                        break;
                    case 7:
                        system("CLS");
                        cout<<"Enter file name"<<endl;
                        getline(cin,file_name);
                        if(file_name==word2)
                        {
                            cout<<"----------------------------------------"<<endl;
                            cout<<"Cannot load the same file more than once"<<endl;
                            cout<<"----------------------------------------"<<endl;
                            break;
                        }
                        word2=file_name;
                        infile.open(file_name);
                        while(infile.fail())
                        {
                            cout<<"Cannot find the file....Enter file name again"<<endl;
                            getline(cin,file_name);
                            infile.open(file_name);
                        }
                        while(!infile.eof())
                        {
                            if(counter4==0)
                            {
                                getline(infile,word);

//                                sometimes it reads the first line as weird symbols don't know thy

                                if(word[0]!='M' & word[0]!='C' & word[0]!='T')
                                {
                                    admins.slicing(word,3);
                                    quiz_2[questions_counter+no_of_questions].type=word;
                                }
                                else
                                    quiz_2[questions_counter+no_of_questions].type=word;
                                counter4++;
                            }
                            else if(counter4==1)
                            {
                                getline(infile,quiz_2[questions_counter+no_of_questions].question);
                                for(int i=0;i<no_of_questions+questions_counter;i++)
                                {
                                    if(quiz_2[questions_counter+no_of_questions].question==quiz_2[i].question)
                                    {
                                        no_of_questions+=no_of_questions_in_file;
                                        cout<<"----------------------------------------"<<endl;
                                        cout<<"Error loading the rest of the file there's a duplicated question"<<endl;
                                        cout<<"----------------------------------------"<<endl;
                                        check4=true;
                                        break;
                                    }
                                }
                                if(check4)
                                    break;
                                no_of_questions_in_file+=1;
                                quiz_2[questions_counter+no_of_questions].question_id=no_of_questions+questions_counter+1;
                                questions_counter+=1;
                                counter4++;
                            }
                            else
                            {
                                if(quiz_2[questions_counter+no_of_questions-1].type=="MCQ")
                                {
                                    getline(infile,quiz_2[choices_counter+no_of_questions].choices[counter4-2]);
                                    counter4++;
                                    if(counter4==6)
                                    {
                                        no_of_mcq_questions++;
                                        choices_counter+=1;
                                        counter4=0;
                                    }
                                }
                                else if(quiz_2[questions_counter+no_of_questions-1].type=="TF")
                                {
                                    getline(infile,quiz_2[choices_counter+no_of_questions].choice);
                                    if(quiz_2[choices_counter+no_of_questions].choice!="true" & quiz_2[choices_counter+no_of_questions].choice!="false")
                                    {
                                        no_of_questions+=no_of_questions_in_file-1;
                                        cout<<"------------------------------------------------"<<endl;
                                        cout<<"File hasn't been loaded completely as there's an invalid answer in one of the questions"<<endl;
                                        cout<<"------------------------------------------------"<<endl;
                                        check4=true;
                                        break;
                                    }
                                    no_of_tf_questions++;
                                    choices_counter+=1;
                                    counter4=0;
                                }
                                else if(quiz_2[questions_counter+no_of_questions-1].type=="COMPLETE")
                                {
                                    getline(infile,quiz_2[choices_counter+no_of_questions].answer);
                                    if(quiz_2[choices_counter+no_of_questions].answer=="")
                                    {
                                        no_of_questions+=no_of_questions_in_file-1;
                                        cout<<"---------------------------------------------------------------------------------------"<<endl;
                                        cout<<"File hasn't been loaded completely as there's an invalid answer in one of the questions"<<endl;
                                        cout<<"---------------------------------------------------------------------------------------"<<endl;
                                        check4=true;
                                        break;
                                    }
                                    no_of_complete_questions++;
                                    choices_counter+=1;
                                    counter4=0;
                                }
                            }
                        }
                        if(check4)
                            break;
                        no_of_questions+=no_of_questions_in_file;
                        cout<<"----------------------------------"<<endl;
                        cout<<"Your file has been loaded successfully"<<endl;
                        cout<<"----------------------------------"<<endl;
                        infile.close();
                        break;
                    case 8:
                        break;
                    default:
                        cout<<"-----------------------"<<endl;
                        cout<<"invalid input"<<endl;
                        cout<<"-----------------------"<<endl;
                }
            }
        }
        else
        {
            cout<<"----------------------------------"<<endl;
            cout<<"Wrong username or password"<<endl;
            cout<<"----------------------------------"<<endl;
            continue;
        }
        if(player_ans==1 || admin_ans==1)
        {
            counter3=0;
            continue;
        }
        if(player_ans==7 || player_ans==8 || ans2=="e" || ans3=="b")
        {
            cout<<"----------------------------------"<<endl;
            cout<<"Thanks for using my program"<<endl;
            cout<<"----------------------------------"<<endl;
            break;
        }
        counter3++;
    }
    return 0;
}

bool login(player players,admin admins)
{
    bool check=false;
    string username,password;
    cout<<"-----------------------------------------"<<endl;
    cout<<"\t\tLogin: "<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"Please enter your username: ";
    getline(cin,username);
    cout<<"Please enter your password: ";
    getline(cin,password);
    for(int i=0;i<no_of_users;i++)
    {
        if(players.username[i]==username)
        {
            if(players.password[i]==password)
            {
                user_id=i;
                check=true;
                break;
            }
        }
        else if(admins.username[i]==username)
        {
            if(admins.password[i]==password)
            {
                user_id=i;
                check=true;
                break;
            }
        }

    }
    return check;
}

bool sign_up(player &players,admin &admins,string user_type)
{
    string new_username;
    bool check=true;
    if(user_type=="admin")
    {
        admins.type[no_of_users]=user_type;
        cout<<"Please enter your username: ";
        cin>>new_username;
        for(int i=0;i<no_of_users;i++)
        {
            while(new_username==admins.username[i] || new_username==players.username[i])
            {
                cout<<"Username already taken please enter a new one"<<endl;
                cin>>new_username;
            }
        }
        admins.username[no_of_users]=new_username;
        cout<<"Please enter your password: ";
        cin>>admins.password[no_of_users];
        cout<<"Enter your first name"<<endl;
        cin>>admins.first_name[no_of_users];
        cout<<"Enter your last name"<<endl;
        cin>>admins.last_name[no_of_users];
    }
    else if(user_type=="player")
    {
        players.type[no_of_users]=user_type;
        cout<<"Please enter your username: ";
        cin>>new_username;
        for(int i=0;i<no_of_users;i++)
        {
            while(new_username==admins.username[i] || new_username==players.username[i])
            {
                cout<<"Username already taken please enter a new one"<<endl;
                cin>>new_username;
            }
        }
        players.username[no_of_users]=new_username;
        cout<<"Please enter your password: ";
        cin>>players.password[no_of_users];
        cout<<"Enter your first name"<<endl;
        cin>>players.first_name[no_of_users];
        cout<<"Enter your last name"<<endl;
        cin>>players.last_name[no_of_users];
    }
    else
        check=false;
    return check;
}
