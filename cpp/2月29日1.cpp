
#include <cstdio>
#include <cstring>
int main()
{
    char first_month[12], last_month[12];
    int first_day, first_year, last_day, last_year;
    int T, ly_count;
    while(scanf("%d", &T)!=EOF)
    {
        for(int i=1; i<=T; ++i)
        {
            scanf("%s %d, %d", first_month, &first_day, &first_year);
            scanf("%s %d, %d", last_month, &last_day, &last_year);
            ly_count = 0;
            if(strcmp(first_month,"January")==0 || (strcmp(first_month,"February")==0&&first_day<=29))
            {
                --first_year;
            }
            if(strcmp(last_month,"January")==0 || (strcmp(last_month,"February")==0&&last_day<29))
            {
                --last_year;
            }
            ly_count = (last_year>>2)-(first_year>>2);
            ly_count = ly_count -(last_year/100-first_year/100);
            ly_count += ((last_year/400-first_year/400));
            printf("Case #%d: %d\n", i, ly_count);
        }
    }
    return 0;
}

