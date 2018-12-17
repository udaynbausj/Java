#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#include <unistd.h>
using namespace std;

struct bigGraph
{
    int id;
    string name;
    vector<string> additional_info;
    vector<int> child_nodes;
    vector<int> parent_node;
};

void addedge(map<int, bigGraph> &mp, int source, int dest, bigGraph bg[])
{
    bg[source].child_nodes.push_back(dest);
    bg[dest].parent_node.push_back(source);
    mp[source] = bg[source];
    mp[dest] = bg[dest];
}

void printGraphInfo(map<int, bigGraph> mp)
{
    cout << "\nRetrieving the Graph's Information : " << endl;
    usleep(5000);
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
    {
        cout << "\nNode id  : " << itr->first;
        bigGraph b = itr->second;
        cout << "\nRetrieving " << b.name << "'s info : ";
        cout << "\nName of the Node : " << b.name;
        cout << "\nImmediate children : ";
        for (int j = 0; j < b.child_nodes.size(); j++)
        {
            cout << b.child_nodes[j] << " ";
        }
        cout << "\nParent children : ";
        for (int j = 0; j < b.parent_node.size(); j++)
        {
            cout << b.parent_node[j] << " ";
        }
        cout << "\n\n";
    }
}

void getImmediateParents(map<int, bigGraph> mp, set<int> s)
{
    int nodeid;
    cout << "\nPlease enter the node id : ";
    cin >> nodeid;
    if (s.find(nodeid) != s.end())
    {
        bigGraph b = mp[nodeid];
        cout << "\nGetting Immeditate Parent Nodes : )\n" << endl;
        for (int i = 0; i < b.parent_node.size(); i++)
        {
            cout << b.parent_node[i] << " ";
        }
    }
    else
    {
        cout << "\nUnregistered Node : ) ";
    }
}

void getImmediateChildren(map<int, bigGraph> mp, set<int> s)
{
    int nodeid;
    cout << "\nPlease enter the node id : )" << endl;
    cin >> nodeid;
    if (s.find(nodeid) != s.end())
    {
        bigGraph b = mp[nodeid];
        cout << "\nGetting Immediate Children Node : ) " << endl;
        for (int i = 0; i < b.child_nodes.size(); i++)
        {
            cout << b.child_nodes[i] << " ";
        }
    }
}

int main()
{

    cout << "How many Vertices are you planning ? \n";
    int vertices, edges, node1, node2, nodeid;
    string nodename;
    cin >> vertices;
    bigGraph bg[10000];

    set<int> registered_nodes;

    cout << "\nEnter 'Node id' , 'Node name' : \n";

    for (int i = 0; i < vertices; i++)
    {
        cin >> nodeid >> nodename;
        registered_nodes.insert(nodeid);
        bg[nodeid].id = nodeid;
        bg[nodeid].name = nodename;
    }
    map<int, bigGraph> mp;
    cout << "\nHow many edges are you planning : ?\n";
    cin >> edges;
    cout << "\nEnter source node first , dest node second : \n";
    for (int i = 0; i < edges; i++)
    {
        cin >> node1 >> node2;

        if (registered_nodes.find(node1) != registered_nodes.end())
        {

            addedge(mp, node1, node2, bg);
        }
        else
        {
            cout << "\nYou have entered Unregistered Node : ";
        }
    }

    cout << "please select one of the options : )" << endl;

    cout << "\n1.Get the immediate parents of a node, passing the node id as input parameter."<< "\n2.Get the immediate children of a node, passing the node id as input parameter."<< "\n3.Get the ancestors of a node, passing the node id as input parameter."<< "\n4.Get the descendants of a node, passing the node id as input parameter."<< "\n5.Delete dependency from a tree, passing parent node id and child node id."<< "\n6.Delete a node from a tree, passing node id as input parameter. This should delete all the dependencies of the node."<<"\n7.Add a new dependency to a tree, passing parent node id and child node id. This should check for cyclic dependencies."<<"\n8.Add a new node to tree. This node will have no parents and children. Dependency will be established by calling the 7 number API.";
    cout<<"\n\n\n";
    int userchoice;
    cin>>userchoice;
    if (userchoice == 1)
    {
        getImmediateParents(mp,registered_nodes);
    }else if(userchoice==2){
        getImmediateChildren(mp,registered_nodes);
    }
}