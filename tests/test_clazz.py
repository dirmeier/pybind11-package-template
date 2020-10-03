"""
Test suite for clazz methods

"""

import numpy as np

from example.example import Example


def test_clazz():
    cl = Example(np.array([1, 2, 3]))
    cl.add(2)
    assert cl.get() == [3, 4, 5]
