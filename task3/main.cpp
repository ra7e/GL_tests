#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <grp.h>
#include <pwd.h>
#include <iostream>


using namespace std;

char* permissions (char *file, struct stat *st)
{
    char *mode_val = (char*)malloc(sizeof(char) * 10);
    mode_t perm = st->st_mode;
    mode_val[0] = (perm & S_IRUSR) ? 'r' : '-';
    mode_val[1] = (perm & S_IWUSR) ? 'w' : '-';
    mode_val[2] = (perm & S_IXUSR) ? 'x' : '-';
    mode_val[3] = (perm & S_IRGRP) ? 'r' : '-';
    mode_val[4] = (perm & S_IWGRP) ? 'w' : '-';
    mode_val[5] = (perm & S_IXGRP) ? 'x' : '-';
    mode_val[6] = (perm & S_IROTH) ? 'r' : '-';
    mode_val[7] = (perm & S_IWOTH) ? 'w' : '-';
    mode_val[8] = (perm & S_IXOTH) ? 'x' : '-';
    mode_val[9] = '\0';
    return mode_val;
}

int main(int argc, char **argv)
{
    DIR *dir;
    struct dirent *tmp;
    struct stat statbuf;
    dir = opendir("."); // open current directory

    if(dir == NULL)
    {
        cout << "Error. Unable to open directory" << endl;
        exit(1);
    }

    while((tmp = readdir(dir)) != NULL)
    {
        if(stat(tmp->d_name, &statbuf) == -1)
        {
            cout << "Error 1"<<endl;
            exit(1);
        }
        struct passwd *pw = getpwuid(statbuf.st_uid);
        struct group *gr = getgrgid(statbuf.st_gid);

        //cout<<endl;
        cout << permissions(tmp->d_name, &statbuf)<<"\t";
        cout << pw->pw_name<<"\t";
        cout << gr->gr_name<<"\t";
        cout << statbuf.st_size << "\t";
        cout << tmp->d_name << "\n";
    }

    closedir(dir);
    return 0;
}
