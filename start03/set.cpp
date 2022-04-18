
#include "set.h"

const treenode *find(const treenode *n, const std::string &s)
{
   while (n)
   {
      int res = s.compare(n->value);
      if (res > 0)
         n = n->right;
      else if (res < 0)
         n = n->left;
      else
         return n;
   }
   return n;
}

treenode **find(treenode **n, const std::string &s)
{
   while (*n != nullptr)
   {
      int cmp = s.compare((*n)->value);
      if (cmp < 0)
      {
         if ((*n)->left != nullptr)
         {
            n = &((*n)->left);
         }
         else
         {
            return n;
         }
      }
      else if (cmp > 0)
      {
         if ((*n)->right != nullptr)
         {
            n = &((*n)->right);
         }
         else
         {
            return n;
         }
      }
      else
      {
         return n;
      }
   }
   return n;
}

size_t size(const treenode *n)
{
   size_t sz = 0;
   if (n == nullptr)
      return sz;
   size_t ls = size(n->left);
   size_t rs = size(n->right);
   return (1 + ls + rs);
}

size_t height(const treenode *n)
{
   if (n == nullptr)
      return 0;
   size_t h = 0;
   size_t lh = height(n->left);
   size_t rh = height(n->right);
   h = (lh > rh ? lh : rh) + 1;
   return h;
}

void deallocate(treenode *n)
{
   if (n == nullptr) return;
   deallocate(n->left);
   deallocate(n->right);
   delete n;
}

treenode * makecopy(const treenode *n)
{
   if (n == nullptr) return nullptr;
   treenode *newtree = new treenode(n->value);
   if (n->left){
      newtree->left = makecopy(n->left);
   }
   if (n->right){
      newtree->right = makecopy(n->right);
   }
   return newtree;
}

void print(std::ostream &out, const treenode *n, unsigned int indent)
{
   for (unsigned int i = 0; i != indent; ++i)
      out << "|  ";
   if (n)
   {
      out << (n->value) << "\n";
      print(out, n->left, indent + 1);
      print(out, n->right, indent + 1);
   }
   else
      out << "#\n";
}

// Both the upperbound and the lowerbound are strict,
// we use pointers, so that they can be absent.

void checkbetween(const treenode *n,
                  const std::string *lowerbound,
                  const std::string *upperbound)
{
   while (n)
   {
      if (lowerbound && *lowerbound >= n->value)
      {
         std::cout << "value " << (n->value);
         std::cout << " is not above lower bound " << *lowerbound << "\n";
         throw std::runtime_error("tree not correct");
      }

      if (upperbound && n->value >= *upperbound)
      {
         std::cout << "value " << (n->value);
         std::cout << "is not below upperbound " << *upperbound << "\n";
         throw std::runtime_error("tree not correct");
      }

      checkbetween(n->left, lowerbound, &(n->value));
      lowerbound = &(n->value);
      n = n->right;
   }
}

unsigned int log_base2(size_t s)
{
   if (s == 0 || s == 1)
      return 0;
   int res = 2, pow = 1;
   while (res * 2 <= s)
   {
      res *= 2;
      pow++;
   }
   return pow;
}

bool set::contains(const std::string &s) const
{
   if (find(tr, s) != nullptr)
   {
      return true;
   }
   return false;
}

bool set::insert(const std::string &s)
{
   if (tr == nullptr){
      tr = new treenode(s);
      return true;
   }
   treenode *f = *find(&tr, s);
   int cmp = s.compare(f->value);
   if (cmp == 0)
   {
      return false;
   }
   else if (cmp > 0)
   {
      f->right = new treenode(s);
      return true;
   }
   else
   {
      f->left = new treenode(s);
      return true;
   }
}

size_t set::size() const
{
   return ::size(tr);
}

size_t set::height() const
{
   return ::height(tr);
}

bool set::empty() const
{
   if (tr == nullptr)
      return true;
   return false;
}

set::~set()
{
   deallocate(tr);
}

void set::clear()
{
   deallocate(tr);
   tr = nullptr;
}

set::set(const set &other)
{
   tr = makecopy(other.tr);
}

set &set::operator=(const set &other)
{
   if (this != &other)
   {
      deallocate(tr);
      tr = makecopy(other.tr);
   }
   return *this;
}

void set::checksorted() const
{
   ::checkbetween(tr, nullptr, nullptr);
}

void set::print(std::ostream &out, unsigned int indent) const
{
   ::print(out, tr, indent);
}
