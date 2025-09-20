#ifndef __cplusplus
typedef enum
{
    Low = 0, Mid = 1, High = 2, Max = 3
}quaternary;

//binary operations
//
//logic tables:
//
//A:      B:      AND     OR      XOR     NAND    NOR     XNOR
//0       0       0       0       0       3       3       3
//0       1       0       1       1       3       2       2
//0       2       0       2       2       3       1       1
//0       3       0       3       3       3       0       0
//1       0       0       1       1       3       2       2
//1       1       1       1       0       2       2       3
//1       2       1       2       2       2       1       1
//1       3       1       3       3       2       0       0
//2       0       0       2       2       3       1       1
//2       1       1       2       2       2       1       1
//2       2       2       2       0       1       1       3
//2       3       2       3       3       1       0       0
//3       0       0       3       3       3       0       0
//3       1       1       3       3       2       0       0
//3       2       2       3       3       1       0       0
//3       3       3       3       0       0       0       3
//AND = Minimum(A, B)
//OR = Maximum(A, B)
//
//NAND = SQI(Minimum(A, B))
//NOR = SQI(Maximum(A, B))
//
//logic tables:
//
//Input:    SQI:    IQI:    NQI:    PQI:
// 0         3       3       3       3
// 1         2       3       0       3
// 2         1       0       0       3
// 3         0       0       0       0

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

//performs XOR operation (see table above)
quaternary XOR(quaternary a, quaternary b)
{
    if (a == b)
    {
        return Low;
    }

    return (a > b) ? a : b;
}

//performs NAND operation (see table above)
quaternary NAND(quaternary a, quaternary b)
{
    if (a < b)
    {
        switch(a)
        {
            case Low:
            return Max;
            break;

            case Mid:
            return High;
            break;

            case High:
            return Mid;
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
            case Low:
            return Max;
            break;

            case Mid:
            return High;
            break;

            case High:
            return Mid;
            break;

            case Max:
            return Low;
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
            case Mid:
            return High;
            break;

            case High:
            return Mid;
            break;

            case Max:
            return Low;
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
            case Low:
            return Max;
            break;

            case Mid:
            return High;
            break;

            case High:
            return Mid;
            break;

            case Max:
            return Low;
            break;
        }
    }
}

//performs XNOR operation (see table above)
quaternary XNOR(quaternary a, quaternary b)
{
    if (a == b)
    {
        return Max;
    }
    else if (a > b)
    {
        switch (a)
        {
            case Low:
            return Max;
            break;

            case Mid:
            return High;
            break;

            case High:
            return Mid;
            break;

            case Max:
            return Low;
            break;
        }
    }

    switch (b)
    {
        case Low:
        return Max;
        break;

        case Mid:
        return High;
        break;

        case High:
        return Mid;
        break;

        case Max:
        return Low;
        break;
    }
}

//performs SQI inversion (see table above)
quaternary SQI_invert(quaternary a)
{
    switch (a)
    {
        case Low:
        return Max;
        break;

        case Mid:
        return High;
        break;

        case High:
        return Mid;
        break;

        case Max:
        return Low;
        break;
    }
}

//performs IQI inversion (see table above)
quaternary IQI_invert(quaternary a)
{
    if (a == Mid || a == Low)
    {
        return Max;
    }
    else 
    {
        return Low;
    }
}

//performs NQI inversion (see table above)
quaternary NQI_invert(quaternary a)
{
    if (a == Low)
    {
        return Max;
    }
    else
    {
        return Low;
    }
}

//performs PQI inversion (see table above)
quaternary PQI_invert(quaternary a)
{
    if (a == Max)
    {
        return Low;
    }
    else
    {
        return Max;
    }
}
#else
class Quaternary
{
    enum LogicState
    {
        low = 0, mid = 1, high = 2, max = 3,
    };

    LogicState state;

public:
    //constructor
    Quaternary(LogicState logicalState)
    {
         state = logicalState;
    }
    //default constructor
    Quaternary()
    {
        state = LogicState::low;
    }

    static LogicState Low()
    {
        return LogicState::low;
    }

    static LogicState Mid()
    {
        return LogicState::mid;
    }

    static LogicState High()
    {
        return LogicState::high;
    }

    static LogicState Max()
    {
        return LogicState::max;
    }

    LogicState State()
    {
        return state;
    }

    //SQI_Invert
    constexpr LogicState operator!()
    {
        switch (state)
        {
            case LogicState::low:
            return LogicState::max;
            break;

            case LogicState::mid:
            return LogicState::high;
            break;

            case LogicState::high:
            return LogicState::mid;
            break;

            case LogicState::max:
            return LogicState::low;
            break;
        }
    }

    //IQI_Invert
    constexpr LogicState operator~()
    {
        switch (state)
        {
            case LogicState::low:
            return LogicState::max;
            break;

            case LogicState::mid:
            return LogicState::max;
            break;

            default:
            return LogicState::low;
            break;
        }
    }

    //NQI_Invert
    constexpr LogicState operator+()
    {
        switch (state)
        {
            case LogicState::low:
            return LogicState::max;
            break;

            default:
            return LogicState::low;
            break;
        }
    }

    //PQI_Invert
    constexpr LogicState operator-()
    {
        switch (state)
        {
            case LogicState::max:
            return LogicState::low;
            break;

            default:
            return LogicState::max;
            break;
        }
    }

    //QAND
    constexpr LogicState operator&&(const Quaternary& b) const
    {
        return (this->state < b.state) ? this->state : b.state;
    }

    //QOR
    constexpr LogicState operator||(const Quaternary& b) const
    {
        return (this->state > b.state) ? this->state : b.state;
    }
    
    //QXOR
    constexpr LogicState operator^(const Quaternary& b) const
    {
        if (this->state == b.state)
        {
            return LogicState::low;
        }

        return (this->state > b.state) ? this->state : b.state;
    }

    //QNAND
    constexpr LogicState operator&(const Quaternary& b) const
    {
        if (this->state < b.state)
        {
            switch (this->state)
            {
                case LogicState::low:
                return LogicState::max;
                break;

                case LogicState::mid:
                return LogicState::high;
                break;

                case LogicState::high:
                return LogicState::mid;
                break;

                case LogicState::max:
                return LogicState::low;
                break;
            }
        }

        switch (b.state)
        {
            case LogicState::low:
            return LogicState::max;
            break;

            case LogicState::mid:
            return LogicState::high;
            break;

            case LogicState::high:
            return LogicState::mid;
            break;

            case LogicState::max:
            return LogicState::low;
            break;
        }
    }

    //QNOR
    constexpr LogicState operator|(const Quaternary& b) const
    {
        if (this->state > b.state)
        {
            switch (this->state)
            {
                case LogicState::low:
                return LogicState::max;
                break;

                case LogicState::mid:
                return LogicState::high;
                break;

                case LogicState::high:
                return LogicState::mid;
                break;

                case LogicState::max:
                return LogicState::low;
                break;
            }
        }

        switch (b.state)
        {
            case LogicState::low:
            return LogicState::max;
            break;

            case LogicState::mid:
            return LogicState::high;
            break;

            case LogicState::high:
            return LogicState::mid;
            break;

            case LogicState::max:
            return LogicState::low;
            break;
        }
    }

    //QXNOR
    constexpr LogicState operator%(const Quaternary& b) const
    {
        if (this->state == b.state)
        {
            return LogicState::max;
        }
        else if (this->state > b.state)
        {
            switch (this->state)
            {
                case LogicState::low:
                return LogicState::max;
                break;

                case LogicState::mid:
                return LogicState::high;
                break;

                case LogicState::high:
                return LogicState::mid;
                break;

                case LogicState::max:
                return LogicState::low;
                break;
            }
        }

        switch (b.state)
        {
            case LogicState::low:
            return LogicState::max;
            break;

            case LogicState::mid:
            return LogicState::high;
            break;

            case LogicState::high:
            return LogicState::mid;
            break;

            case LogicState::max:
            return LogicState::low;
            break;
        }
    }
};

#endif
