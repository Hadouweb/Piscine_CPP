#ifndef SPAN_HPP
# define SPAN_HPP

class Span {
public:
    Span(void);
    Span(Span const & src);

    ~Span(void);

    Span & operator=(Span const & rhs);
};

#endif