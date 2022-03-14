
#include "queue.h"

queue::queue( );

queue::queue( const queue& q );

const queue& queue::operator = ( const queue& q );

queue::~queue( );

queue::queue( std::initializer_list< std::string > init );

void queue::push( const std::string& s );

void queue::pop( );

void queue::clear( );

void queue::reset( size_t s );

const std::string& queue::peek( ) const;

size_t queue::size( ) const;

bool queue::empty( ) const;

void queue::print( std::ostream& out ) const;


