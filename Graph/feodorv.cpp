#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define IOSIZE (2*1024*1024)

char input[IOSIZE];
char *iptr = input;
int ihas = 0, ifinished = 0;

#define ISSPACE(x) ((x) == ' ' || (x) == '\n')
#define ISDIGIT(x) ((x) >= '0' && (x) <= '9')

#define SKIP_SPACES() while( ISSPACE(*iptr) ) iptr++
#define GET_NUM(x) while( ISDIGIT(*iptr) ) (x) = (x << 3) + (x << 1) + (*iptr++ - '0')

void ioRead( void )
{
    int rest = ihas - (int) (iptr - input), ic;

    if( ifinished || rest > 64 ) return;
    if( rest > 0 ) memmove( input, iptr, rest);

    ic = fread( &input[rest], 1, IOSIZE-1-rest, stdin);
    if( ic > 0 )
        ihas = rest + ic;
    else
    {
        ifinished = 1;
        ihas = rest;
    }

    input[ihas] = '\0';
    iptr = input;
}

int inputNum( void )
{
    int num = 0;

    ioRead();

    SKIP_SPACES();
    GET_NUM(num);

    return num;
}

char output[IOSIZE];
char *optr = output;

void ioWrite( void )
{
    int filled = (int) (optr - output);
    if( filled > 0 ) fwrite( output, 1, filled, stdout);
    optr = output;
}

void outputString( const char *s )
{
    for( ; *s != '\0'; ++s) *optr++ = *s;
    if( (IOSIZE - (int) (optr - output)) < 64 ) ioWrite();
}

void outputNum( int v )
{
    if( v <= 0 )
        outputString( "0" );
    else
    {
        char rbuf[32];
        int off = 31;
        rbuf[off--] = '\0';
        while( v != 0 )
        {
            rbuf[off--] = v % 10 + '0';
            v /= 10;
        }
        outputString( &rbuf[off+1] );
    }
}




int getnum( const char *s )
{
    int num = 0;
    while( *s >= '0' && *s <= '9' ) num = 10 * num + (*s++ - '0');
    return num;
}

const int p10[11] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000,
                      100000000, 1000000000, 0x7fffffff
                    };

void printnum( int start, int len)
{
    outputString( "0" );
    outputNum( start );

    if( len > 1 )
    {
        int i, end = start + len - 1;

        for( i = 10; i >= 1; --i)
            if( (start % p10[i]) / p10[i-1] != (end % p10[i]) / p10[i-1] ) break;

        outputString( "-" );
        outputNum( end % p10[i] );
    }

    outputString( "\n" );
}

int main( void )
{
    int cs = 0;

    for(;;)
    {
        int N = inputNum();
        int i, start, last, cur, len = 0;

        if( N <= 0 ) break;
        outputString( "Case " );
        outputNum( ++cs );
        outputString( ":\n" );

        for( i = 0; i < N; ++i)
        {
            cur = inputNum();
            if( cur < 100 || cur > 2000000000 ) continue;
            if( len > 0 && cur == last+1 )
                len++;
            else
            {
                if( len > 0 ) printnum( start, len);
                start = cur;
                len = 1;
            }
            last = cur;
        }
        if( len > 0 ) printnum( start, len);

        outputString( "\n" );
    }

    ioWrite();
    return 0;
}
