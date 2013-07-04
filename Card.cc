#include "Card.h"

Card::Card(
        value_type value
        ) :
    _value( value ),
    _next( NULL )
{

}

std::ostream&
operator<<(
        std::ostream& os,
        const Card& c
        )
{
    os << static_cast<uint32_t>(c._value);
    return os;
}
