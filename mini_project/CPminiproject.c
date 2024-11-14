#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 100
#define MAX_CAST_LENGTH 100
#define MAX_SHOWS_MOVIES 100
#define MAX_USERS 100

struct Date
{
    int day, month, year;
};

struct Cast
{
    char name[MAX_NAME_LENGTH];
    char tvShows[MAX_SHOWS_MOVIES][MAX_NAME_LENGTH];
    char movies[MAX_SHOWS_MOVIES][MAX_NAME_LENGTH];
    int cti;
    int cmi;
};

struct TV_Show
{
    char name[MAX_NAME_LENGTH];
    struct Date firstTelecastDate;
    int totalEpisodes;
    struct Date originalReleaseDate;
    char cast[MAX_CAST_LENGTH]; // 2d array of strings
    char producer[MAX_NAME_LENGTH];
    char writer[MAX_NAME_LENGTH];
};

struct Movie
{
    char name[MAX_NAME_LENGTH];
    struct Date releaseDate;
    char cast[MAX_CAST_LENGTH];
    char producer[MAX_NAME_LENGTH];
    char writer[MAX_NAME_LENGTH];
    char soundtrack[MAX_NAME_LENGTH];
    char productionCompany[MAX_NAME_LENGTH];
    float budget;
    float boxOfficeCollection;
};

struct ViewingDetails
{
    char name[MAX_NAME_LENGTH];
    struct Date viewingDate;
    float rating;
};

struct User
{
    int identificationNumber;
    struct Date registrationDate;
    float subvalid;
    char subscriptionPlan[MAX_NAME_LENGTH];
    char preferences[10];
    struct ViewingDetails viewdm[MAX_SHOWS_MOVIES];
    int nm;
    struct ViewingDetails viewds[MAX_SHOWS_MOVIES];
    int ns;
};

// Function prototypes
void addTVShow(struct TV_Show tvShows[], int *numTVShows, struct Cast casts[], int *numCasts);                              //
void addMovie(struct Movie movies[], int *numMovies, struct Cast casts[], int *numCasts);                                   //
void searchByCast(char name[], struct TV_Show a[], int ntv, struct Movie m[], int nm);                                      //
void identifyMaxViewedMovie(struct User u[], int lu, int mo, int ye);                                                       //
void listShowsMoviesForSameCastingDetails(struct TV_Show tv[], int ltv, struct Movie m[], int lm, struct Cast c[], int lc); //
void adduser(struct User u[], int *l)
{
    int i = *l;
    u[i].identificationNumber = i;
    printf("enter the registeration date");
    scanf("%d", &u[i].registrationDate.day);
    printf("month==");
    scanf("%d", &u[i].registrationDate.month);
    printf("year==");
    scanf("%d", &u[i].registrationDate.year);
    printf("enter the sub plan->");
    scanf("%[^\n]s", u[i].subscriptionPlan);
    if (strcmp(u[i].subscriptionPlan, "platinum user"))
    {
        u[i].subvalid = 3;
    }
    else if ((2023 - (u[i].registrationDate.year)) >= 1 && (12 - (u[i].registrationDate.month)) >= 6)
    {
        u[i].subvalid = 1.5;
    }
    else
    {
        u[i].subvalid = 1;
    }
    printf("enter the prefered genre of the user--->>");
    scanf("%[^\n]s", u[i].preferences);
    printf("enter the viewing details-->>");
    int nu;
    printf("\n enter the num of movies: "); // movie wathched
    scanf("%d", &nu);
    u[i].nm = nu;
    for (int k = 0; k <= nu - 1; k++)
    {
        printf("entr the name of movie watched->");
        scanf("%[^\n]s", u[i].viewdm[k].name);
        printf("enter the viewing date->\n enter day:");
        scanf("%d", &u[i].viewdm[k].viewingDate.day);
        printf("enter the month->");
        scanf("%d", &u[i].viewdm[k].viewingDate.month);
        printf("enter the year->");
        scanf("%d", &u[i].viewdm[k].viewingDate.year);
        printf("enterr rating out of 5->.");
        scanf("%f", &u[i].viewdm[k].rating);
    }
    printf("\nenter the num of tv shows->");
    scanf("%d", &nu);
    u[i].nm = nu;
    for (int k = 0; k <= nu - 1; k++)
    {
        printf("entr the name of tv shows watched->");
        scanf("%[^\n]s", u[i].viewds[k].name);
        printf("enter the viewing date->\n enter day:");
        scanf("%d", &u[i].viewds[k].viewingDate.day);
        printf("enter the month->");
        scanf("%d", &u[i].viewds[k].viewingDate.month);
        printf("enter the year->");
        scanf("%d", &u[i].viewds[k].viewingDate.year);
        printf("enterr rating out of 5->.");
        scanf("%f", &u[i].viewds[k].rating);
    }
    i++;
    *l = i;
}
void updatetvShow(struct TV_Show a[], int lt, struct Cast casts[], int *lc)
{
    int ui;
    char k[100];
    printf("enter the name of tv show:");
    scanf("%[^\n]s", k);
    for (int i = 0; i <= lt; i++)
    {
        if (strcmp(k, a[i].name) == 0)
        {
            ui = i;
            break;
        }
    }

    int ch = 8;
    while (ch != 0)
    {
        printf("enter what you want to update \n1:name\n2:first telecastdate\n3:cast\n4:producer\n5:writer\n0:end");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            scanf("%[^\n]s", a[ui].name);
            break;
        case 2:
            printf("day:");
            scanf("%d", a[ui].firstTelecastDate.day);
            printf("enter month:");
            scanf("%d", a[ui].firstTelecastDate.month);
            printf("year:");
                scanf("%d", a[ui].firstTelecastDate.year);
            break;
        case 3:
            scanf("%[^\n]s", a[ui].cast);
            {
                int co = 0, t = *lc;
                for (int io = 0; io <= t; io++)
                {
                    if (strcmp(a[ui].cast, casts[io].name) == 0)
                    {
                        co = co + 1;
                        casts[io].cti++;
                        strcpy(casts[io].tvShows[casts[io].cti], a[ui].name);
                        break;
                    }
                }
                if (co == 0)
                {
                    t++;
                    casts[t].cti = 0;
                    strcpy(casts[t].tvShows[casts[t].cti], a[ui].name);
                }
                *lc = t;
            }
            break;
        case 4:
            scanf("%[^\n]s", a[ui].producer);
            break;
        case 5:
            scanf("%[^\n]s", a[ui].writer);
            break;
        case 0:
            goto end;
            break;
        }
    }
end:
}
void updatemovie(struct Movie a[], int lt, struct Cast casts[], int *lc)
{
    int ui;
    char k[100];
    printf("enter the name of tv movie:");
    scanf("%[^\n]s", k);
    for (int i = 0; i <= lt; i++)
    {
        if (strcmp(k, a[i].name) == 0)
        {
            ui = i;
            break;
        }
    }
    int ch = 9;
    while (ch != 0)
    {
        printf("enter what you want to update \n1:name\n2:first release date\n3:cast\n4:producer\n5:writer\n0:end");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            scanf("%[^\n]s", a[ui].name);
            break;
        case 2:
            printf("day:");
            scanf("%d", a[ui].releaseDate.day);
            printf("enter month:");
            scanf("%d", a[ui].releaseDate.month);
            printf("year:");
                scanf("%d", a[ui].releaseDate.year);
            break;
        case 3:
            scanf("%[^\n]s", a[ui].cast);
            {
                int co = 0, t = *lc;
                for (int io = 0; io <= t; io++)
                {
                    if (strcmp(a[ui].cast, casts[io].name) == 0)
                    {
                        co = co + 1;
                        casts[io].cti++;
                        strcpy(casts[io].tvShows[casts[io].cti], a[ui].name);
                        break;
                    }
                }
                if (co == 0)
                {
                    t++;
                    casts[t].cti = 0;
                    strcpy(casts[t].tvShows[casts[t].cti], a[ui].name);
                }
                *lc = t;
            }
            break;
        case 4:
            scanf("%[^\n]s", a[ui].producer);
            break;
        case 5:
            scanf("%[^\n]s", a[ui].writer);
            break;
        case 0:
            goto end;
            break;
        }
    }
end:
}
int main()
{
    struct TV_Show tvShows[MAX_SHOWS_MOVIES];
    int numTVShows = 0;

    struct Movie movies[MAX_SHOWS_MOVIES];
    int numMovies = 0;

    struct Cast casts[MAX_CAST_LENGTH];
    int numCasts = 0;

    struct User users[MAX_USERS];
    int numUsers = 0;

    int ch = 100;
    while (ch != 0)
    {
        printf("enter your choice >>");
        printf("enter 1:Add tv shows;\n2:add movies\n3:search by casts\n4:creat account");
        printf("\n5:updatemovie\n6: update tv show\n7: identify MaxViewedMovie in a month \n8:list shows movies of a perticular cast");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            addTVShow(tvShows, &numTVShows, casts, &numCasts);
            break;
        case 2:
            addMovie(movies, &numMovies, casts, &numCasts);
            break;
        case 3:
            printf("enter the name of cast-->");
            char temp[100];
            scanf("%[^\n]", temp);
            searchByCast(temp, tvShows, numTVShows, movies, numMovies);
            break;
        case 4:
            adduser(users, &numUsers);
            break;
        case 5:
            updatemovie(movies, numMovies, casts, &numCasts);
            break;
        case 6:
            updatetvShow(tvShows, numTVShows, casts, &numCasts);
            break;
        case 7:
            int mo, ye;
            printf("entr the month:");
            scanf("%d", &mo);
            printf("year:");
            scanf("%d", &ye);
            identifyMaxViewedMovie(users, numUsers, mo, ye);
        case 8:
            listShowsMoviesForSameCastingDetails(tvShows, numTVShows, movies, numMovies, casts, numCasts);
            break;
        }
    }
    return 0;
}

void addTVShow(struct TV_Show a[], int *numTVShows, struct Cast casts[], int *numCasts)
{
    char k[100];
    int i = *numTVShows, t = *numCasts;
    printf("enter the name of tv shoe-->>");
    scanf("%[^\n]s", k);
    strcpy(a[i].name, k);
    printf("enter the first telecast date-->>");
    printf("DAY=");
    scanf("%d", &a[i].firstTelecastDate.day);
    printf("month=");
    scanf("%d", &a[i].firstTelecastDate.month);
    printf("year=");
    scanf("%d", &a[i].firstTelecastDate.year);
    printf("enter the casts-->");
    scanf("%[^\n]s", k);
    strcpy(a[i].cast, k);
    /*casts[t].name = a[i].cast;
    casts[t].tvShows[]=; */
    {
        int co = 0;
        for (int io = 0; io <= t; io++)
        {
            if (k == casts[io].name)
            {
                co = co + 1;
                casts[io].cti++;
                strcpy(casts[io].tvShows[casts[io].cti], a[i].name);
                break;
            }
        }
        if (co == 0)
        {
            t++;
            casts[t].cti = 0;
            strcpy(casts[t].tvShows[casts[t].cti], a[i].name);
        }
    }
    i++;
    *numTVShows = i;
    *numCasts = t;
    /*for (int k = 0; k < 4; k++)
    {
        scanf("%[^\n]s", &a[i].cast[k]);
        casts[t]=a[i].cast[k];
        printf("enter info about cast --> ")
    }*/
}

void addMovie(struct Movie a[], int *numMovies, struct Cast casts[], int *numCasts)
{ /*char name[MAX_NAME_LENGTH];
     struct Date releaseDate;
     char cast[MAX_CAST_LENGTH];
     char producer[MAX_NAME_LENGTH];
     char writer[MAX_NAME_LENGTH];
     char soundtrack[MAX_NAME_LENGTH];
     char productionCompany[MAX_NAME_LENGTH];
     float budget;
     float boxOfficeCollection;*/

    int i = *numMovies, t = *numCasts;
    char k[100];
    printf("enter the name of movie-->>");
    scanf("%[^\n]s", k);
    strcpy(a[i].name, k);
    printf("enter the release date-->>");
    printf("DAY=");
    scanf("%d", &a[i].releaseDate.day);
    printf("month=");
    scanf("%d", &a[i].releaseDate.month);
    printf("year=");
    scanf("%d", &a[i].releaseDate.year);
    printf("producer-->");
    scanf("%[^\n]s", k);
    strcpy(a[i].producer, k);
    printf("enter the writer");
    scanf("%[^\n]s", k);
    strcpy(a[i].writer, k);
    printf("enter the main soundtrack-->");
    scanf("%[^\n]s", k);
    strcpy(a[i].soundtrack, k);
    printf("entr the production company-->");
    scanf("%[^\n]s", k);
    strcpy(a[i].productionCompany, k);
    printf("enter the budget-->");
    scanf("%f", &a[i].budget);
    printf("enter box office collection-->");
    scanf("%f", &a[i].boxOfficeCollection);
    printf("enter the casts-->");
    scanf("%[^\n]s", k);
    strcpy(a[i].cast, k);
    // strcpy(casts[t].name, k);
    {
        int co = 0;
        for (int io = 0; io <= t; io++)
        {
            if (k == casts[io].name)
            {
                co = co + 1;
                casts[io].cti++;
                strcpy(casts[io].tvShows[casts[io].cti], a[i].name);
                break;
            }
        }
        if (co == 0)
        {
            t++;
            casts[t].cti = 0;
            strcpy(casts[t].tvShows[casts[t].cti], a[i].name);
        }
    }
    // strcpy(casts[t].tvShows[cti],a[i].name);
    i++;
    *numMovies = i;
    *numCasts = t;
    /*struct Cast
{
    char name[MAX_NAME_LENGTH];
    char tvShows[MAX_SHOWS_MOVIES][MAX_NAME_LENGTH];
    char movies[MAX_SHOWS_MOVIES][MAX_NAME_LENGTH];
    int cti;
    int cmi;
};*/
}

void searchByCast(char name[], struct TV_Show a[], int ntv, struct Movie m[], int nm)
{
    int k = 0;
    printf("TV shows by cast %s are ->\n", name);
    for (int i = 0; i <= ntv; i++)
    {
        if (strcmp(name, a[i].cast) == 0)
        {
            printf("%d", k);
            printf("TV show: %s\n", a[i].name);
            printf("writer :%s\n ", a[i].writer);
            printf("Producer:%s\n", a[i].producer);
            printf("total episodes: %d \n", a[i].totalEpisodes);
            printf("telecast date: %d-%d-%d", a[i].firstTelecastDate.day, a[i].firstTelecastDate.month, a[i].firstTelecastDate.year);
            k++;
        }
    }
    k = 0;
    printf("Movies by cast %s are ->\n", name);
    for (int i = 0; i <= ntv; i++)
    {
        if (strcmp(name, m[i].cast) == 0)
        {
            printf("%d", k);
            printf("Movie: %s\n", m[i].name);
            printf("writer :%s\n ", m[i].writer);
            printf("Producer:%s\n", m[i].producer);
            printf("soundtrack: %s\n", m[i].soundtrack);
            printf("release date: %d-%d-%d", m[i].releaseDate.day, m[i].releaseDate.month, m[i].releaseDate.year);
            k++;
        }
    }
}

void identifyMaxViewedMovie(struct User u[], int lu, int mo, int ye)
{
    char mna[100][10]; // recenrt max movie
                       /*int co = 0 , com = 0,ciu=0; // max count
                       for (int i = 0; i <= lu - 1; i++)
                       {
                           for (int k = 0; k <= u[i].nm; k++)
                           {
                               if (u[i].viewdm[k].viewingDate.year == ye && u[i].viewdm[k].viewingDate.month == mo)
                               {
                                   co=co+1;
                                   strcpy(rm,u[i].viewdm[k].name);
                                   com=co;
                                   ciu=i;
                                   goto here;
                               }
                           }
                       }
                       here:
                       */
    int co = 0, mnum = 0 /*movie name added*/;
    for (int i = 0; i <= lu - 1; i++) // user
    {
        for (int k = 0; k <= u[i].nm; k++) // movie viewed by a user
        {
            if (u[i].viewdm[k].viewingDate.year == ye && u[i].viewdm[k].viewingDate.month == mo) // req movies collection
            {
                co = 0;
                for (int ko = 0; ko <= mnum - 1; ko++)
                {
                    if (strcmp(u[i].viewdm[k].name, mna[ko]) == 0)
                    {
                        co++;
                    }
                }
                if (co < 1)
                {
                    strcpy(mna[mnum], u[i].viewdm[k].name);
                    mnum++;
                }
            }
        }
    }
    int c = 0, ml = 0, mi = 0;
    for (int i = 0; i <= mnum; i++) // req movie
    {
        for (int r = 0; r <= lu - 1; r++) // user
        {
            for (int k = 0; k <= u[i].nm; k++) // movie viewed by a user
            {
                if (strcmp(u[r].viewdm[k].name, mna[i]) == 0)
                {
                    c++;
                    if (c > ml)
                    {
                        ml = c;
                        mi = i;
                    }
                }
            }
        }
    }
    printf("max viewed movie is %s", mna[mi]);
}

void listShowsMoviesForSameCastingDetails(struct TV_Show tvShows[], int numTVShows, struct Movie movies[], int numMovies, struct Cast casts[], int numCasts)
{
    for (int i = 0; i < numTVShows; ++i)
    {
        printf("TV Show: %d\n", i + 1);
        struct TV_Show currentShow = tvShows[i];

        // Compare current TV show casting details with movies
        for (int j = 0; j < numMovies; ++j)
        {
            struct Movie currentMovie = movies[j];
            bool matchingDetails = true;

            // Check if the casting details match
            for (int k = 0; k < MAX_CAST_LENGTH; ++k)
            {
                if (/*Yaha Comparison logic for casting details wala part karle na please */)
                {
                    // Details match
                }
                else
                {
                    matchingDetails = false;
                    break;
                }
            }

            if (matchingDetails)
            {
                printf("Movie %d shares casting details with TV Show %d\n", j + 1, i + 1);
                // Print or store the movie details as needed
            }
        }
    }
}
