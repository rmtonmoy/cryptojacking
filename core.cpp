
#include<bits/stdc++.h>
using namespace std;
#define MAX     1000
#define D(x)    cerr << #x " = " << (x) << endl

char line[MAX+5];
vector<string> links;
vector<string> main_file;

int main()
{
    FILE *fp;
    fp = fopen("links_source.txt", "r");

    while(fgets(line, MAX, fp)){
        if(strlen(line) && line[strlen(line)-1] == '\n'){
            line[strlen(line) - 1] = 0;
        }
        links.push_back(line);
    }
    fclose(fp);

    if(links.empty()) return 0;

    fp = fopen("links_source.txt", "w");
    for(int i = 1; i < (int) links.size(); i++)
    {
        string l = links[i];
        fputs(l.c_str(), fp);
        fputs("\n", fp);
    }
    fclose(fp);

    fp = fopen("links_destination.txt", "a");
    string l = links[0];
    fputs(l.c_str(), fp);
    fputs("\n", fp);
    fclose(fp);

    int counter = 0;
    fp = fopen("main.js", "r");
    while(fgets(line, MAX, fp)){
        main_file.push_back(line);
        counter++;
    }
    fclose(fp);

    string new_line = "    await page.goto(\"https:\\\\";
    // CHANGE LINE 22: hardcoded
    new_line = new_line + links[0];
    new_line = new_line + "\")\n";
    D(new_line);
    main_file[22] = new_line;

    fp = fopen("main.js", "w");
    for(int i = 0; i < (int) main_file.size(); i++)
    {
        string l = main_file[i];
        fputs(l.c_str(), fp);
    }
    fclose(fp);

    return 0;
}
