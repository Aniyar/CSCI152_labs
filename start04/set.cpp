
#include "set.h"

size_t case_insensitive::hash(const std::string &s)
{
   size_t hash = 4129;
   for (size_t i = 0; i < s.size(); ++i)
      hash = 33 * hash + (unsigned char)tolower(s[i]);
   return hash;
}

bool case_insensitive::equal(const std::string &s1, const std::string &s2)
{
   if (s1.length() != s2.length())
      return false;
   int i = 0;
   while (i < s1.length())
   {
      if (tolower(s1[i]) != tolower(s1[i]))
         return false;
      i++;
   }
   return true;
}

bool set::insert_norehash(const std::string &s)
{
   using namespace case_insensitive;
   size_t hashval = hash(s);
   int n = hashval % buckets.size();
   for (const auto &str : buckets[n])
   {
      if (equal(str, s))
         return false;
   }
   buckets[n].push_back(s);
   set_size++;
   return true;
}

void set::consider_rehash()
{
   bool flag = true;
   while ((set_size / buckets.size()) > max_load_factor)
   {
      buckets.resize(2 * buckets.size());
      flag = false;
   }
   if (flag) return; // if buckets size was not changed, we don't need to rehash anything
   
   for (int i = 0; i < buckets.size(); i++)
   {
      for (auto it = buckets[i].begin(); it != buckets[i].end(); ++it)
      {
         std::string temp = *it;
         remove(*it);
         insert(temp);
      }
   }
}

set::set(std::initializer_list<std::string> init,
         double max_load_factor)
    : max_load_factor(max_load_factor)
{
   for (const auto &str : init)
   {
      insert(str);
   }
}

bool set::contains(const std::string &s) const
{
   using namespace case_insensitive;
   size_t hashval = hash(s);
   int n = hashval % buckets.size();
   for (auto it = buckets[n].begin(); it != buckets[n].end(); ++it)
   {
      if (equal(*it, s))
         return true;
   }
   return false;
}

bool set::insert(const std::string &s)
{
   consider_rehash();
   return insert_norehash(s);
}

bool set::remove(const std::string &s)
{
   using namespace case_insensitive;
   size_t hashval = hash(s);
   int n = hashval % buckets.size();
   for (auto it = buckets[n].begin(); it != buckets[n].end(); ++it)
   {
      if (equal(*it, s))
      {
         buckets[n].erase(it);
         return true;
      }
   }
   return false;
}

size_t set::size() const
{
   size_t n = 0;
   for (int i = 0; i < buckets.size(); i++)
   {
      for (auto it = buckets[i].begin(); it != buckets[i].end(); ++it)
      {
         n++;
      }
   }
   return n;
}

bool set::empty() const
{
   if (size() == 0)
      return true;
   return false;
}

void set::clear()
{
   for (int i = 0; i < buckets.size(); i++)
   {
      buckets[i].clear();
   }
}

void set::print(std::ostream &out) const
{
   // out << "[ ";
   for (int i = 0; i < buckets.size(); i++)
   {
      out << "{ ";
      for (auto it = buckets[i].begin(); it != buckets[i].end(); it++)
      {
         if (next(it) == buckets[i].end()) out << *it << " ";
         else out << *it << ", ";
      }
      out << "}\n";
   }
   // out << "]\n";
}
