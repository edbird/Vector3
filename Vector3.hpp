#ifndef VECTOR3_HPP
#define VECTOR3_HPP


#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>



template<typename T>
class vector3
{


    public:

    friend inline void swap(vector3& l, vector3& r)
    {
        using std::swap;

        swap(l._x_, r._x_);
        swap(l._y_, r._y_);
        swap(l._z_, r._z_);
    }

    vector3()
        : _x_{static_cast<T>(0)}
        , _y_{static_cast<T>(0)}
        , _z_{static_cast<T>(0)}
    {
    }

    vector3(const T x, const T y, const T z)
        : _x_{x}
        , _y_{y}
        , _z_{z}
    {
    }


    virtual
    ~vector3()
    {
    }

    
    vector3(const vector3& other)
        : _x_{other._x_}
        , _y_{other._y_}
        , _z_{other._z_}
    {
    }


    vector3(vector3&& other)
        //: _x_{other._x_}
        //, _y_{other._y_}
        //, _z_{other._z_}
        : vector3()
    {
        swap(*this, other);
    }

    // this works because the pass by value creates a copy of the argument
    vector3& operator=(vector3 other)
    {
        //if(this != &other)
        //{
        //    _x_ = other._x_;
        //    _y_ = other._y_;
        //    _z_ = other._z_;
        //}

        swap(*this, other);

        return *this;
    }

    
    vector3 operator-() const
    {
        return vector3<T>(-_x_, -_y_, -_z_);
    }
    

    private:

    inline bool compare(const vector3& l, const vector3& r)
    {
        return (l._x_ == r._x_) && (l._y_ == r._y_) && (l._z_ == r._z_);
    }

    inline bool mod2_compare(const vector3& l, const vector3& r)
    {
        return mod2(l) == mod2(r);
    }

    inline T mod2(const vector3& v)
    {
        return (v._x_ * v._x_) + (v._y_ * v._y_) + (v._z_ * v._z_);
    }

    inline void add(const vector3& v)
    {
        _x_ += v._x_;
        _y_ += v._y_;
        _z_ += v._z_;
    }

    inline void sub(const vector3& v)
    {
        _x_ -= v._x_;
        _y_ -= v._y_;
        _z_ -= v._z_;
    }

    template<typename U>
    inline void mult(const U m)
    {
        _x_ *= static_cast<T>(m);
        _y_ *= static_cast<T>(m);;
        _z_ *= static_cast<T>(m);;
    }

    template<typename U>
    inline void div(const U d)
    {
        _x_ /= static_cast<T>(d);
        _y_ /= static_cast<T>(d);;
        _z_ /= static_cast<T>(d);;
    }

    /*
    inline void invert()
    {
        _x_ = -_x_;
        _y_ = -_y_;
        _z_ = -_z_;
    }
    */

    inline T get_x() const
    {
        return _x_;
    }

    inline T get_y() const
    {
        return _y_;
    }

    inline T get_z() const
    {
        return _z_;
    }

    // scale vector
    // multiply each dimension by a scaling factor
    // simular to multiply method, except that scaling factors can be different
    // for each dimension
    // element-wise multiply
    inline void scale(const vector3<T>& v)
    {
        _x_ *= v._x_;
        _y_ *= v._y_;
        _z_ *= v._z_;
    }


    public:

    // TODO: change name to ElementWiseMultiply
    void Scale(const vector3<T>& v)
    {
        scale(v);
    }

    /*
    double GetX() const
    {
        return get_x();
    }

    double GetY() const
    {
        return get_y();
    }

    double GetZ() const
    {
        return get_z();
    }
    */

    ////////////////////////////////////////////////////////////////////////////
    // GET / SET
    ////////////////////////////////////////////////////////////////////////////

    T GetX() const { return get_x(); }
    T GetY() const { return get_y(); }
    T GetZ() const { return get_z(); }


    ////////////////////////////////////////////////////////////////////////////
    // BINARY ARITHMATIC
    ////////////////////////////////////////////////////////////////////////////
    
    vector3& operator+=(const vector3& v)
    {
        add(v);
        return *this;
    }

    vector3& operator-=(const vector3& v)
    {
        sub(v);
        return *this;
    }

    template<typename U>
    vector3& operator*=(const U m)
    {
        mult(m);
        return *this;
    }

    template<typename U>
    vector3& operator/=(const U d)
    {
        div(d);
        return *this;
    }

    //inline bool operator==(const vector3& l, const vector3& r);

    //inline bool operator!=(const vector3& l, const vector3& r);

    //inline bool operator<(const vector3& l, const vector3&r);

    //inline bool operator>(const vector3& l, const vector3&r);

    //inline bool operator<=(const vector3& l, const vector3&r);

    //inline bool operator>=(const vector3& l, const vector3&r);


    std::string string_format_default() const
    {
        std::ostringstream oss;
        oss << "(" << _x_ << "," << _y_ << "," << _z_ << ")";
        return oss.str();
    }

    //std::ostream& operator<<(std::ostream& os, const vector3& v)

    private:

    

    T _x_;
    T _y_;
    T _z_;


};


////////////////////////////////////////////////////////////////////////////////
// COMPARISON OPERATORS
////////////////////////////////////////////////////////////////////////////////

template<typename T>
inline bool operator==(const vector3<T>& l, const vector3<T>& r)
{
    return compare(l, r);
}

template<typename T>
inline bool operator!=(const vector3<T>& l, const vector3<T>& r)
{
    return !operator==(l, r);
}

template<typename T>
inline bool operator<(const vector3<T>& l, const vector3<T>&r)
{
    return mod_compare(l, r);
}

template<typename T>
inline bool operator>(const vector3<T>& l, const vector3<T>&r)
{
    return operator<(r, l);
}

template<typename T>
inline bool operator<=(const vector3<T>& l, const vector3<T>&r)
{
    return !operator>(l, r);
}

template<typename T>
inline bool operator>=(const vector3<T>& l, const vector3<T>&r)
{
    return !operator<(l, r);
}


////////////////////////////////////////////////////////////////////////////////
// BINARY ARITHMATIC OPERATORS
////////////////////////////////////////////////////////////////////////////////

template<typename T>
inline vector3<T> operator+(vector3<T> l, const vector3<T> &r)
{
    l += r;
    return l;
}

template<typename T>
inline vector3<T> operator-(vector3<T> l, const vector3<T> &r)
{
    l -= r;
    return l;
}

template<typename T, typename U>
inline vector3<T> operator*(vector3<T> l, const U m)
{
    l *= m;
    return l;
}

template<typename T, typename U>
inline vector3<T> operator*(const U m, vector3<T> r)
{
    r *= m;
    return r;
}

template<typename T, typename U>
inline vector3<T> operator/(vector3<T> l, const U d)
{
    l /= d;
    return l;
}

template<typename T, typename U>
inline vector3<T> operator/(const U d, vector3<T> r)
{
    r /= d;
    return r;
}


////////////////////////////////////////////////////////////////////////////////
// STREAM OPERATORS
////////////////////////////////////////////////////////////////////////////////

template<typename T>
std::ostream& operator<<(std::ostream& os, const vector3<T>& v)
{
    os << v.string_format_default();
    return os;
}


////////////////////////////////////////////////////////////////////////////////
// INVERSION
////////////////////////////////////////////////////////////////////////////////

/*
template<typename T>
vector3<T> operator-(const vector3<T> &v)
{
    //return vector3<T>(-v._x_, -v._y_);
    return vector3<T>(-v.GetX(), -v.GetY(), -v.GetZ());
}
*/


#endif // VECTOR3_HPP
