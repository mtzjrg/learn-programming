import pytest
from jar import Jar


def test_init():
    jar = Jar()
    assert jar.capacity == 12
    assert jar.size == 0


def test_str():
    jar = Jar()
    assert str(jar) == "" and jar.size == 0
    jar.deposit(1)
    assert str(jar) == "🍪" and jar.size == 1
    jar.deposit(11)
    assert str(jar) == "🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪" and jar.size == 12


def test_deposit():
    jar = Jar()
    with pytest.raises(ValueError):
        jar.deposit(13)


def test_withdraw():
    jar = Jar()
    with pytest.raises(ValueError):
        jar.withdraw(1)
