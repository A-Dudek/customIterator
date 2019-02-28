#include <iostream>
#include <cstddef>
#include <algorithm>
#include <vector>
#include <iterator>

struct Container
{
    int tab[10]{1, 1, 3, 7, 5, 6, 7, 8, 4, 10};

    template <typename T>
    struct Iterator
    {
        T *pos;

        using value_type = T;
        using reference = value_type &; //int&
        using difference_type = std::ptrdiff_t;
        using pointer = value_type *; //int*
        using iterator_category = std::random_access_iterator_tag;

        Iterator &operator++()
        {
            pos += 1;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator tmp = *this;
            pos += 1;
            return tmp;
        }

        Iterator &operator--()
        {
            pos -= 1;
            return *this;
        }

        Iterator operator--(int)
        {
            Iterator tmp = *this;
            pos -= 1;
            return tmp;
        }

        Iterator operator+(difference_type n) const
        {
            Iterator tmp = *this;
            tmp.pos = pos + n * 1;
            return tmp;
        }

        difference_type operator-(Iterator it) const
        {
            return (it.pos - pos) / 1;
        }

        Iterator operator-(difference_type n) const
        {
            Iterator tmp = *this;
            tmp.pos = pos - n;
            return tmp;
        }

        bool operator==(Iterator y) const
        {
            return pos == y.pos;
        }

        bool operator!=(Iterator y) const
        {
            return pos != y.pos;
        }

        reference operator*() const
        {
            return *pos;
        }

        Iterator &operator+=(difference_type n)
        {
            pos = pos + n * 1;
            return *this;
        }

        Iterator &operator-=(difference_type n)
        {
            pos = pos - n * 1;
            return *this;
        }

        reference operator[](difference_type n)
        {
            return *(pos + n);
        }

        bool operator<(Iterator y) const
        {
            return pos < y.pos;
        }

        bool operator>(Iterator y) const
        {
            return pos > y.pos;
        }

        bool operator>=(Iterator y) const
        {
            return !(pos < y.pos);
        }

        bool operator<=(Iterator y) const
        {
            return !(pos > y.pos);
        }
    };

    using iterator = Iterator<int>;
    using const_iterator = Iterator<const int>;

    iterator begin()
    {
        iterator tmp;
        tmp.pos = tab;
        return tmp;
    }

    iterator end()
    {
        iterator tmp;
        tmp.pos = tab + 10;
        return tmp;
    }

    const_iterator cbegin() const
    {
        const_iterator tmp;
        tmp.pos = tab;
        return tmp;
    }

    const_iterator cend() const
    {
        const_iterator tmp;
        tmp.pos = tab + 10;
        return tmp;
    }

    const_iterator begin() const
    {
        const_iterator tmp;
        tmp.pos = tab;
        return tmp;
    }

    const_iterator end() const
    {
        const_iterator tmp;
        tmp.pos = tab + 10;
        return tmp;
    }

    std::reverse_iterator<iterator> rbegin()
    {

        return std::make_reverse_iterator(end());
    }

    std::reverse_iterator<iterator> rend()
    {
        return std::make_reverse_iterator(begin());
    }

    std::reverse_iterator<const_iterator> rbegin() const
    {

        return std::make_reverse_iterator(end());
    }

    std::reverse_iterator<const_iterator> rend() const
    {
        return std::make_reverse_iterator(begin());
    }

    std::reverse_iterator<const_iterator> crbegin() const
    {

        return std::make_reverse_iterator(end());
    }

    std::reverse_iterator<const_iterator> crend() const
    {
        return std::make_reverse_iterator(begin());
    }
};

int main(int argc, char const *argv[])
{
    Container k;
    std::sort(k.begin(), k.end());

    std::vector<int> v{1, 2, 3, 4};
    auto it = v.begin();
    *it = 1;

    for (auto it = k.rbegin(); it != k.rend(); ++it)
    {
        std::cout << *it << " ";
    }
}
