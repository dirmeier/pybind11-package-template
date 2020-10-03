import numpy as np

from clazz import clazz


class Example:
    """
    An example clazz
    """

    def __init__(self, vec: np.ndarray):
        """
        Constructor

        Create an object of class 'clazz' that wraps an integer numpy array.

        Parameters
        ----------
        vec: np.ndarray
            a vector of type int that is wrapped by this class
        """

        self._clazz = clazz(vec)

    def get(self) -> np.ndarray:
        """
        Getter for vec

        Gets a reference to the wrapped vector

        Return
        ------
        numpy.ndarray:
            returns the wrapped vector as numpy array
        """
        return self._clazz.get()

    def add(self, k: int):
        """
        Add function

        Add an integer to the vector

        Parameter
        ---------
        int:
            integer that is added to the vector
        """

        self._clazz.add(k)
