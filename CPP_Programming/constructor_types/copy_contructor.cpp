#include <iostream>
#include <utility>
class MetaData
{
public:
    MetaData (int size, const std::string& name)
        : _name( name )
        , _size( size )
    {}
 
    // copy constructor
    MetaData (const MetaData& other)
        : _name( other._name )
        , _size( other._size )
    {}
 
    // move constructor
    MetaData (MetaData&& other)
        : _name( std::move(other._name) )
        , _size( other._size )
    {}
 
    std::string getName () const { return _name; }
    int getSize () const { return _size; }
    private:
    std::string _name;
    int _size;
};

class ArrayWrapper
{
public:
    // default constructor produces a moderately sized array
    ArrayWrapper ()
        : _p_vals( new int[ 64 ] )
        , _metadata( 64, "ArrayWrapper" )
    {}
 
    ArrayWrapper (int n)
        : _p_vals( new int[ n ] )
        , _metadata( n, "ArrayWrapper" )
    {}
 
    // move constructor
    ArrayWrapper (ArrayWrapper&& other)
        : _p_vals( other._p_vals  )
        , _metadata( std::move(other._metadata) )
    {
        other._p_vals = NULL;
    }
 
    // copy constructor
    ArrayWrapper (const ArrayWrapper& other)
        : _p_vals( new int[ other._metadata.getSize() ] )
        , _metadata( other._metadata )
    {
        for ( int i = 0; i < _metadata.getSize(); ++i )
        {
            _p_vals[ i ] = other._p_vals[ i ];
        }
    }
    ~ArrayWrapper ()
    {
        delete [] _p_vals;
    }
private:
    int *_p_vals;
    MetaData _metadata;
};

