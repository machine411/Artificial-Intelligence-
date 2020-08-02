#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
bool secondline=false;
vector<int> result;
int resultnode=0;
int reslutpath=0;


class Node
{
    public:
    int x;
    int y;
    int dir;
    
};
class Link
{
    public:
    Node data;
    Link *next;
};
class Stack
{
    public:
    Link *top;
    public:
    Stack();
    Node Pop();
    void Push(Node e);
    Node Top();
    bool empty();
};

Stack::Stack()
{
    top=NULL;
}

void Stack::Push(Node e)
{
    Link *P;
    P=new Link;
    P->data=e;
    P->next=top;
    top=P;
}
Node Stack::Pop()
{
    Node Temp;
    Link *P;
    P=top;
    top=top->next;
    Temp=P->data;
    delete P;
    return Temp;
}
Node Stack::Top()
{
    return top->data;
}

bool Stack::empty()
{
    if(top==NULL) return 1;
    else return 0;
}


void Print(Stack p);
bool Maze(int **maze,int sx,int sy,int m,int n);

bool Maze(int **maze,int sx,int sy,int m,int n)

{   int move[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    Stack son,father;
    Node Temp1,Temp2;
    int x,y,loop;
    
    Temp1.x=sx;
    Temp1.y=sy;
    son.Push(Temp1);
    father.Push(Temp1);
    maze[sx][sy]=-1;
    
    while(!son.empty())
    {
        Temp2=son.Top();
        if(!(father.Top().x==son.Top().x&&father.Top().y==son.Top().y))
        father.Push(Temp2);
        
        for(loop=0;loop<4;loop++)
        {
            x=Temp2.x+move[loop][0];
            y=Temp2.y+move[loop][1];
            if(maze[x][y]==0)
            {
                Temp1.x=x;
                Temp1.y=y;
                maze[x][y]=-1;
                son.Push(Temp1);
                resultnode++;
                
            }
            if((x==(m))&&(y==(n)))
            {
                Temp1.x=m;
                Temp1.y=n;
                Temp1.dir=0;
                father.Push(Temp1);
                Print(father);
                return 1;
            }
        }
        if(father.Top().x==son.Top().x&&father.Top().y==son.Top().y)
        {
            father.Pop();
            son.Pop();
        }
    }
    return 0;
}

void Print(Stack p)
{
    
    Stack t;
    int a,b;
    Node data;
    Link *temp;
    temp=new Link;
    temp->data=p.Pop();
    t.Push(temp->data);
    delete temp;
    while(!p.empty())
    {
        temp=new Link;
        temp->data=p.Pop();
        
        a=t.Top().x-temp->data.x;
        b=t.Top().y-temp->data.y;
        if(a==1) temp->data.dir=1;
        else if(b==1) temp->data.dir=2;
        else if(a==-1) temp->data.dir=3;
        else if(b==-1) temp->data.dir=4;
        t.Push(temp->data);
        delete temp;
    }
    
    while(!t.empty())
    {
        reslutpath++;
        data=t.Pop();
        
        result.push_back(data.dir);
    }
    
    
}




int main(int argc, char* argv[])
{
    
    
    string filename;
    filename=string(argv[1]);
    int getgoal[4];
    for(int i=0;i<4;i++)
    {
        getgoal[i]=atoi(argv[i+2]);
    
    }
    int x1,x2,y1,y2;
    x1=getgoal[0]+1;
    x2=getgoal[2]+1;
    y1=getgoal[1]+1;
    y2=getgoal[3]+1;

    ifstream testfile;

    testfile.open(filename);
    
    int number[2];
    
    for(int i=0;i<2;i++)
    {
        testfile  >> number[i];
        secondline=true;
    }
   
    int width=number[0];
    int height=number[1];

    int **maze;
    
    int m=height;
    int n=width;
    maze=new int *[m+2];
    for(int i= 0;i<m+2;i++)
    
    {
        maze[i]=new int[n+2];
    }
    
    while (testfile&&secondline) {
        for(int i=1; i <=height; i++){
            for (int j=1; j<=width; j++){
                testfile >> maze[i][j];
            }
        }
    }
    for(int i=0;i<m+2;i++)
    maze[i][0]=maze[i][n+1]=1;
    for(int i=0;i<n+2;i++)
    maze[0][i]=maze[m+1][i]=1;
    
    if(Maze(maze,y1,x1,y2,x2))
    {
        cout<<resultnode<<" "<<reslutpath-1<<endl;
        
        for(int i=0;i<result.size();i++)
        {
            
            switch(result[i])
            
            {
                case 1:cout<<"D ";break;
                case 2:cout<<"R ";break;
                case 3:cout<<"U ";break;
                case 4:cout<<"L ";break;
            }
        }
        cout<<"\n";}
    else
    {
        cout<<resultnode<<" "<<"0"<<endl;
        cout<<"X\n";
        return 0;
    }
}

