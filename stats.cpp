// Provided by:   ____________Carter Beebe__________
// Lab:           ____________OTT 182________
// Course number: ____________CIS-221________
// I typed all of the code and worked on all of my code by myself.
// FILE: stats.h
// CLASS PROVIDED: Statistician
//   (a class to keep track of statistics on a sequence of real numbers)
//   This class is part of the namespace main_savitch_2C.
//
// VALUE SEMANTICS for the Statistician class:
// Assignments and the copy constructor may be used with Statistician objects.

#include "stats.h"
namespace main_savitch_2C
{
  //  Postcondition: The object has been initialized, and is ready to accept
  //  a sequence of numbers. Various statistics will be calculated about the
  //  sequence.
  Statistician::Statistician ( )
  {
    count_ = 0;
    total_= 0.0;
    tinyest_ = 0.0;
    largest_ = 0.0;
    mean_ = 0.0;
  }
  // constructor with variables
  Statistician::Statistician (int count, double total, double tinyest, double largest, double mean)
  {
    count_ = count;
    total_ = total;
    tinyest_ = tinyest;
    largest_ = largest;
    mean_ = mean;
  }

  //  The number r has been given to the Statistician as the next number in
  //  its sequence of numbers.
  void Statistician::next(double r)
  {
    count_ ++;
    total_ += r;
    if (length() == 1){
      tinyest_ = r;
      largest_ = r;
    }
    else {
        if (r <= tinyest_){
          tinyest_ = r;
        }
        if (r >= largest_){
          largest_ = r;
        }
      }
  }
  //  Postcondition: The Statistician has been cleared, as if no numbers had
  //  yet been given to it.
  void Statistician::reset( )
  {
    count_ = 0;
    total_ = 0.0;
    tinyest_ = 0.0;
    largest_ = 0.0;
  }

  //  Postcondition: The return value is the length of the sequence that has
  //  been given to the Statistician (i.e., the number of times that the
  //  next(r) function has been activated).
  int Statistician::length( ) const
  {
    return count_;
  }

  //  Postcondition: The return value is the sum of all the numbers in the
  //  Statistician's sequence.
  double Statistician::sum( ) const
  {
    return total_;
  }

  //  Precondition: length( ) > 0
  //  Postcondition: The return value is the arithmetic mean (i.e., the
  //  average of all the numbers in the Statistician's sequence).
  double Statistician::mean( ) const
  {
    assert (length() > 0);
    return (total_ / count_);
  }

  //  Precondition: length( ) > 0
  //  Postcondition: The return value is the tinyest number in the
  //  Statistician's sequence.
  double Statistician::minimum( ) const
  {
    assert (length() > 0);
    return tinyest_;
  }

  //  Precondition: length( ) > 0
  //  Postcondition: The return value is the largest number in the
  //  Statistician's sequence.
  double Statistician::maximum( ) const
  {
    assert (length() > 0);
    return largest_;
  }

  //  Postcondition: The Statistician that is returned contains all the
  //  numbers of the sequences of s1 and s2.
  
  Statistician operator + (const Statistician& s1,
			   const Statistician& s2)
  {
    int comblength_;
    double combsum_, combmin_, combmax_, combmean_;
    if ((s1.length() ==0) && (s2.length() == 0)){
      comblength_ = 0;
      combsum_ = 0;
      combmin_ = 0;
      combmax_ = 0;
      combmean_ = 0;
    }
    if ((s1.length() > 0) && (s2.length() == 0)){
      comblength_ = s1.length();
      combsum_ = s1.sum();
      combmin_ = s1.minimum();
      combmax_ = s1.maximum();
      combmean_ = s1.mean();
    }
    if ((s1.length() == 0) && (s2.length() > 0)){
      comblength_ = s2.length();
      combsum_ = s2.sum();
      combmin_ = s2.minimum();
      combmax_ = s2.maximum();
      combmean_ = s2.mean();
    }
    if ((s1.length() > 0) && (s2.length() > 0)){
    comblength_ = s1.length() + s2.length();
    combsum_ = s1.sum() + s2.sum();
      if (s1.minimum() > s2.minimum()){
        combmin_ = s2.minimum();
      }
        else {
          combmin_ = s1.minimum();
        }
      if (s1.maximum() > s2.maximum()){
        combmax_ = s1.maximum();
      }
        else {
          combmax_ = s2.maximum();
        }
    combmean_ = (s1.sum() + s2.sum()) / (s1.length() + s2.length());
    }
   Statistician combstat(comblength_, combsum_, combmin_, combmax_, combmean_);
   return combstat;
  }

  //  Postcondition: The Statistician that is returned contains the same
  //  numbers that s does, but each number has been multiplied by the
  //  scale number.
  Statistician operator * (double scale,
			   const Statistician& s)
  {
    int multilength_;
    double multisum_, multimin_, multimax_, multimean_;
    multilength_ = s.length();
    if (s.length() == 0) {
      multisum_ = 0;
      multimin_ = 0;
      multimax_ = 0;
      multimean_ = 0;
    }
      else {
        multisum_ = s.sum() * scale;
      
        if (s.length() > 0){
        multimin_ = s.minimum() * scale;
        }
        if (s.length() > 0){
        multimax_ = s.maximum() * scale;
        }
        if (s.length() > 0 || s.sum() > 0){
        multimean_ = s.mean() * scale;
        }
      }
       if (multimin_ > multimax_){
        multimin_ = s.maximum() * scale;
        multimax_ = s.minimum() * scale;
       }
       if (multimax_ == 0) {
         multimax_ = 0;
       }
       if (multimin_ == 0){
         multimin_ = 0;
       }
    Statistician multistat(multilength_, multisum_, multimin_, multimax_, multimean_);
    return multistat;
  }

  //  Postcondition: The return value is true if s1 and s2 have zero
  //  length. Also, if the length is greater than zero, then s1 and s2 must
  //  have the same length, the same  mean, the same minimum,
  //  the same maximum, and the same sum.
  bool operator ==(const Statistician& s1,
                   const Statistician& s2)
  {
    if ((s1.length() == 0) & (s2.length() == 0)){
            return true;
    }
    if ((s1.length() == s2.length()) && (s1.mean() == s2.mean()) && (s1.minimum() == s2.minimum())
          && (s1.maximum() == s2.maximum()) && (s1.sum() == s2.sum())) {
               return true;
    }
      else {
        return false;
      }
  }

  //  Postcondition: The return value is false if s1 and s2 have zero
  //  length. Also, if the length is greater than zero, then s1 and s2 must
  //  not have the same length, the same  mean, the same minimum,
  //  the same maximum, and the same sum.
  bool operator !=(const Statistician& s1,
                   const Statistician& s2)
  {
    if ((s1.length() != s2.length()) && (s1.mean() != s2.mean()) && (s1.minimum() != s2.minimum())
          && (s1.maximum() != s2.maximum()) && (s1.sum() != s2.sum())) {
      return false;
      }
        else if ((s1.length() == 0) && (s2.length() == 0)){
          return false;
        }
    else {
      return true;
    }
  }
}

