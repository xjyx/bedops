/*
  FILE: EchoMapVisitor.hpp
  AUTHOR: Scott Kuehn, Shane Neph
  CREATE DATE: Thu Nov  8 13:31:09 PST 2007
  PROJECT: utility
  ID: $Id$
*/

#ifndef ECHO_MAP_BED_VISITOR_HPP
#define ECHO_MAP_BED_VISITOR_HPP

#include <set>


namespace Visitors {

  namespace BedSpecific { // use other/EchoMapVisitor.hpp for numeric types

    template <
              typename Process,
              typename BaseVisitor
             >
    struct EchoMapBed : BaseVisitor {
      typedef BaseVisitor BaseClass;
      typedef Process ProcessType;
      typedef typename BaseVisitor::reference_type RefType;
      typedef typename BaseVisitor::mapping_type MapType;

      explicit EchoMapBed(const ProcessType& pt = ProcessType()) : pt_(pt)
        { /* */ }

      inline void Add(MapType* t) {
        win_.insert(t);
      }

      inline void Delete(MapType* t) {
        win_.erase(t);
      }

      inline void DoneReference() {
        pt_.operator()(win_.begin(), win_.end());
      }

      virtual ~EchoMapBed() { }

    private:
      typedef std::set<MapType*> SType;
      typedef typename SType::iterator SIter;
      ProcessType pt_;
      SType win_;
    };

  } // namespace BedSpecific

} // namespace Visitors


#endif // ECHO_MAP_BED_VISITOR_HPP
