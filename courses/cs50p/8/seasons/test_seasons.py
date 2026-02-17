import pytest

from seasons import convert


def test_str():
    with pytest.raises(ValueError):
        convert("February 6th, 1998")


def test_iso():
    with pytest.raises(ValueError):
        convert("02-06-1998")
