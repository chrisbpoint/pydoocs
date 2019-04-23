""" Test module for the pydoocs module itself. """
import unittest

import pydoocs


class PydoocsModuleTest(unittest.TestCase):
    """ Test class for the pydoocs module itself. """

    def test_members_existence(self):
        pydoocs_members = [element for element in dir(pydoocs) if not element.startswith("__")]
        self.assertEqual(5, len(pydoocs_members))
        self.assertTrue('read' in pydoocs_members)
        self.assertTrue('write' in pydoocs_members)
        self.assertTrue('names' in pydoocs_members)
        self.assertTrue('DoocsException' in pydoocs_members)
        self.assertTrue('PyDoocsException' in pydoocs_members)

    def test_doc_strings(self):
        self.assertEqual(pydoocs.__doc__, "Python bindings to the standard DOOCS client API written in C/C++.")
        self.assertEqual(pydoocs.read.__doc__, "Function to read data from a given DOOCS address.")
        self.assertEqual(pydoocs.write.__doc__, "Function to write data to a given DOOCS address.")
        self.assertEqual(pydoocs.names.__doc__, "Function to query names from a given DOOCS name domain.")
        self.assertEqual(pydoocs.DoocsException.__doc__, "Custom DOOCS exception with "
                                                              "dict_keys(['code', 'message']) in its first argument.")
        self.assertEqual(pydoocs.PyDoocsException.__doc__, "Custom pydoocs exception with specific message.")

    def test_version_attribute(self):
        self.assertTrue('__version__' in dir(pydoocs))
        self.assertEqual("2.0.4", pydoocs.__version__)


