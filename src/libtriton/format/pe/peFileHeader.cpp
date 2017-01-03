//! \file
/*
**  Copyright (C) - Triton
**
**  This program is under the terms of the BSD License.
*/

#include <cstdio>

#include <exceptions.hpp>
#include <peFileHeader.hpp>



namespace triton {
  namespace format {
    namespace pe {

      PeFileHeader::PeFileHeader() {
        this->st.machine                = 0;
        this->st.numberOfSections       = 0;
        this->st.timeDateStamp          = 0;
        this->st.pointerToSymbolTable   = 0;
        this->st.numberOfSymbolTable    = 0;
        this->st.sizeOfOptionalHeader   = 0;
        this->st.characteristics        = 0;
      }


      PeFileHeader::PeFileHeader(const PeFileHeader& copy) {
        this->st.machine                = copy.st.machine;
        this->st.numberOfSections       = copy.st.numberOfSections;
        this->st.timeDateStamp          = copy.st.timeDateStamp;
        this->st.pointerToSymbolTable   = copy.st.pointerToSymbolTable;
        this->st.numberOfSymbolTable    = copy.st.numberOfSymbolTable;
        this->st.sizeOfOptionalHeader   = copy.st.sizeOfOptionalHeader;
        this->st.characteristics        = copy.st.characteristics;
      }


      PeFileHeader::~PeFileHeader() {
      }


      PeFileHeader& PeFileHeader::operator=(const PeFileHeader& copy) {
        if (this == &copy)
            return *this;

        this->st.machine                = copy.st.machine;
        this->st.numberOfSections       = copy.st.numberOfSections;
        this->st.timeDateStamp          = copy.st.timeDateStamp;
        this->st.pointerToSymbolTable   = copy.st.pointerToSymbolTable;
        this->st.numberOfSymbolTable    = copy.st.numberOfSymbolTable;
        this->st.sizeOfOptionalHeader   = copy.st.sizeOfOptionalHeader;
        this->st.characteristics        = copy.st.characteristics;

        return *this;
      }


      void PeFileHeader::parse(const triton::uint8* raw) {
        std::memcpy(&this->st, raw, sizeof(this->st));
      }


      triton::uint16 PeFileHeader::getMachine(void) const {
        return this->st.machine;
      }


      triton::uint16 PeFileHeader::getNumberOfSections(void) const {
        return this->st.numberOfSections;
      }


      triton::uint32 PeFileHeader::getTimeDateStamp(void) const {
        return this->st.timeDateStamp;
      }


      triton::uint32 PeFileHeader::getPointerToSymbolTable(void) const {
        return this->st.pointerToSymbolTable;
      }


      triton::uint32 PeFileHeader::getNumberOfSymbolTable(void) const {
        return this->st.numberOfSymbolTable;
      }


      triton::uint16 PeFileHeader::getSizeOfOptionalHeader(void) const {
        return this->st.sizeOfOptionalHeader;
      }


      triton::uint16 PeFileHeader::getCharacteristics(void) const {
        return this->st.characteristics;
      }

    }; /* pe namespace */
  }; /* format namespace */
}; /* triton namespace */
