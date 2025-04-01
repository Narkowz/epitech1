
static int test_comp ( const void *a, const void *b)
{
return ( strcmp (*( char **)a, *( char **)b) ) ;
}
static void test_disp ( const void *str)
{
printf (" %s", *( char **) str) ;
}

int main ( int argc , const char ** argv )
{
printf (" argv :") ;
disp_array (argv , argc , sizeof (* argv ) , & test_disp ) ;
printf ("\n") ;
argc = uniq_array (argv , argc , sizeof (* argv ) , & test_comp ) ;
printf (" uniq :") ;
disp_array (argv , argc , sizeof (* argv ) , & test_disp ) ;
printf ("\n") ;
sort_array (argv , argc , sizeof (* argv ) , & test_comp ) ;
printf (" sort :") ;
disp_array (argv , argc , sizeof (* argv ) , & test_disp ) ;
printf ("\n") ;
return (0) ;
}