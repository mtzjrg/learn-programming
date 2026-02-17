import pytest

from fuel import convert, gauge


def test_success():
    for i in range(0, 101):
        match i:
            case 0:
                assert gauge(convert("0/10")) == "E"
            case 1:
                assert gauge(convert("1/100")) == "E"
            case 99:
                assert gauge(convert("99/100")) == "F"
            case 100:
                assert gauge(convert("5/5")) == "F"
            case _:
                assert gauge(convert(f"{i}/100")) == f"{i}%"


def test_fail_str():
    with pytest.raises(ValueError):
        convert("three/four")


def test_fail_num():
    with pytest.raises(ValueError):
        convert("1.5/3")
    with pytest.raises(ValueError):
        convert("5/4")
    with pytest.raises(ValueError):
        convert("-3/4")


def test_fail_zero():
    with pytest.raises(ZeroDivisionError):
        convert("4/0")
