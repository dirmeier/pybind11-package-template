#ifndef EXAMPLE_INCLUDE_CLAZZ_HPP_
#define EXAMPLE_INCLUDE_CLAZZ_HPP_

#include <iostream>
#include <vector>

/*!
 * \brief A brief description of the class
 *
 * A longer description of the class
 */
class clazz {
 public:
  /*!
   * \brief Constructor
   *
   * A more elaborate description of the constructor.
   *
   * \param vec an rvalue reference
   */
  explicit clazz(std::vector<int>& vec) : vec_(vec) {}

  /*!
   * \brief Add method
   *
   * A method to add an integer to the vector
   *
   * \param k the value to add to the vector
   * \return void
   */
  void add(int k);

  /*!
   * \brief Getter for the vector
   *
   * Gets the contents of the wrapped vector
   *
   * \return reference to vector
   */
  const std::vector<int>& get() { return vec_; }

  friend std::ostream& operator<<(std::ostream& os, clazz& cl) {
    for (int i = 0; i < (int)cl.vec_.size(); ++i) {
      os << cl.vec_[i];
      if (i < (int)cl.vec_.size() - 1)
        os << ", ";
    }
    return os;
  }

 private:
  std::vector<int> vec_;
};

#endif // EXAMPLE_INCLUDE_CLAZZ_HPP_
