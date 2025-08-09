//quaternary logic library
typedef enum
{
    false = 0, true = 1, third = 2, fourth = 3
}quaternary;

//binary operations
//
//logic tables:
//
//  A     B       AND     OR      NAND        NOR
//
//  0     0        0       0        3           3
//  0     1        0       1        3           2
//  0     2        0       2        3           1
//  0     3        0       3        3           0
//  1     0        0       1        3           2
//  1     1        1       1        2           2
//  1     2        1       2        2           1
//  1     3        1       3        2           0
//  2     0        0       2        3           1
//  2     1        1       2        2           1
//  2     2        2       2        1           1
//  2     3        2       3        1           0
//  3     0        0       3        3           0
//  3     1        1       3        2           0
//  3     2        2       3        1           0
//  3     3        3       3        0           0
//
//AND = Minimum(A, B)
//OR = Maximum(A, B)
//
//NAND = SQI(Minimum(A, B))
//NOR = SQI(Maximum(A, B))

//performs AND operation (see table above)
quaternary AND(quaternary a, quaternary b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

//performs OR operation (see table above)
quaternary OR(quaternary a, quaternary b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

//performs NAND operation (see table above)
quaternary NAND(quaternary a, quaternary b)
{
    if (a < b)
    {
        switch(a)
        {
            case false:
            return fourth;
            break;

            case true:
            return third;
            break;

            case third:
            return true;
            break;

            default:
            return a;
            break;
        }
    }
    else
    {
        switch(b)
        {
            case false:
            return fourth;
            break;

            case true:
            return third;
            break;

            case third:
            return true;
            break;

            case fourth:
            return false;
            break;
        }
    }
}

//performs NOR operation (see table above)
quaternary NOR(quaternary a, quaternary b)
{
    if (a > b)
    {
        switch(a)
        {
            case true:
            return third;
            break;

            case third:
            return true;
            break;

            case fourth:
            return false;
            break;

            default:
            return a;
            break;
        }
    }
    else
    {
        switch(b)
        {
            case false:
            return fourth;
            break;

            case true:
            return third;
            break;

            case third:
            return true;
            break;

            case fourth:
            return false;
            break;
        }
    }
}

//quaternary inversion functions
//
//logic tables:
//
//Input:    SQI:    IQI:    NQI:    PQI:
// 0         3       3       3       3
// 1         2       3       0       3
// 2         1       0       0       3
// 3         0       0       0       0


//performs SQI inversion (see table above)
quaternary SQI_invert(quaternary a)
{
    switch (a)
    {
        case false:
        return fourth;
        break;

        case true:
        return third;
        break;

        case third:
        return true;
        break;

        case fourth:
        return false;
        break;
    }
}

//performs IQI inversion (see table above)
quaternary IQI_invert(quaternary a)
{
    if (a == true || a == false)
    {
        return fourth;
    }
    else 
    {
        return false;
    }
}

//performs NQI inversion (see table above)
quaternary NQI_invert(quaternary a)
{
    if (a == false)
    {
        return fourth;
    }
    else
    {
        return false;
    }
}

//performs PQI inversion (see table above)
quaternary PQI_invert(quaternary a)
{
    if (a == fourth)
    {
        return false;
    }
    else
    {
        return fourth;
    }
}
