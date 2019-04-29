""" Test file for the pydoocs module related tests. """
import unittest

from hamcrest import *


class PydoocsModuleTest(unittest.TestCase):
    """ Test class for the pydoocs module related tests. """

    @classmethod
    def setUpClass(cls):
        import pydoocs
        cls._pydoocs = pydoocs
        cls._pydoocs_members = [member for member in dir(cls._pydoocs) if not member.startswith("__")]

    def test_that_pydoocs_has_the_correct_number_of_members(self):
        assert_that(self._pydoocs_members, has_length(5))
        
    def test_that_all_pydoocs_members_have_the_specified_names(self):
        assert_that("read", is_in(self._pydoocs_members))
        assert_that("write", is_in(self._pydoocs_members))
        assert_that("names", is_in(self._pydoocs_members))
        assert_that("DoocsException", is_in(self._pydoocs_members))
        assert_that("PyDoocsException", is_in(self._pydoocs_members))
        
    def test_that_all_pydoocs_members_have_the_specified_doc_strings(self):
        assert_that(self._pydoocs.__doc__, is_(equal_to("Python bindings to the standard DOOCS client API written "
                                                        "in C/C++.")))
        assert_that(self._pydoocs.read.__doc__, is_(equal_to("Function to read data from a given DOOCS address.")))
        assert_that(self._pydoocs.write.__doc__, is_(equal_to("Function to write data to a given DOOCS address.")))
        assert_that(self._pydoocs.names.__doc__, is_(equal_to("Function to query names from a given DOOCS name "
                                                              "domain.")))
        assert_that(self._pydoocs.DoocsException.__doc__, is_(equal_to("Custom DOOCS exception with dict_keys(['code', "
                                                                       "'message']) in its first argument.")))
        assert_that(self._pydoocs.PyDoocsException.__doc__, is_(equal_to("Custom pydoocs exception with specific "
                                                                         "message.")))

    def test_the_existence_and_correct_value_of_the_version_attribute(self):
        with open("VERSION") as f:
            version = f.read()
        assert_that("__version__", is_in(dir(self._pydoocs)))
        assert_that(self._pydoocs.__version__, is_(equal_to(version)))
