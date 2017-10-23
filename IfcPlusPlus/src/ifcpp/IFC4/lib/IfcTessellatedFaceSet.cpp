/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/IfcPPException.h"
#include "ifcpp/model/IfcPPAttributeObject.h"
#include "ifcpp/model/IfcPPGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4/include/IfcCartesianPointList3D.h"
#include "ifcpp/IFC4/include/IfcIndexedColourMap.h"
#include "ifcpp/IFC4/include/IfcIndexedTextureMap.h"
#include "ifcpp/IFC4/include/IfcPresentationLayerAssignment.h"
#include "ifcpp/IFC4/include/IfcStyledItem.h"
#include "ifcpp/IFC4/include/IfcTessellatedFaceSet.h"

// ENTITY IfcTessellatedFaceSet 
IfcTessellatedFaceSet::IfcTessellatedFaceSet() {}
IfcTessellatedFaceSet::IfcTessellatedFaceSet( int id ) { m_id = id; }
IfcTessellatedFaceSet::~IfcTessellatedFaceSet() {}
shared_ptr<IfcPPObject> IfcTessellatedFaceSet::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcTessellatedFaceSet> copy_self( new IfcTessellatedFaceSet() );
	if( m_Coordinates ) { copy_self->m_Coordinates = dynamic_pointer_cast<IfcCartesianPointList3D>( m_Coordinates->getDeepCopy(options) ); }
	return copy_self;
}
void IfcTessellatedFaceSet::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "= IFCTESSELLATEDFACESET" << "(";
	if( m_Coordinates ) { stream << "#" << m_Coordinates->m_id; } else { stream << "$"; }
	stream << ");";
}
void IfcTessellatedFaceSet::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
const std::wstring IfcTessellatedFaceSet::toString() const { return L"IfcTessellatedFaceSet"; }
void IfcTessellatedFaceSet::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<IfcPPEntity> >& map )
{
	const size_t num_args = args.size();
	if( num_args != 1 ){ std::stringstream err; err << "Wrong parameter count for entity IfcTessellatedFaceSet, expecting 1, having " << num_args << ". Entity ID: " << m_id << std::endl; throw IfcPPException( err.str().c_str() ); }
	readEntityReference( args[0], m_Coordinates, map );
}
void IfcTessellatedFaceSet::getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
	IfcTessellatedItem::getAttributes( vec_attributes );
	vec_attributes.push_back( std::make_pair( "Coordinates", m_Coordinates ) );
}
void IfcTessellatedFaceSet::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes_inverse )
{
	IfcTessellatedItem::getAttributesInverse( vec_attributes_inverse );
	if( m_HasColours_inverse.size() > 0 )
	{
		shared_ptr<IfcPPAttributeObjectVector> HasColours_inverse_vec_obj( new IfcPPAttributeObjectVector() );
		for( size_t i=0; i<m_HasColours_inverse.size(); ++i )
		{
			if( !m_HasColours_inverse[i].expired() )
			{
				HasColours_inverse_vec_obj->m_vec.push_back( shared_ptr<IfcIndexedColourMap>( m_HasColours_inverse[i] ) );
			}
		}
		vec_attributes_inverse.push_back( std::make_pair( "HasColours_inverse", HasColours_inverse_vec_obj ) );
	}
	if( m_HasTextures_inverse.size() > 0 )
	{
		shared_ptr<IfcPPAttributeObjectVector> HasTextures_inverse_vec_obj( new IfcPPAttributeObjectVector() );
		for( size_t i=0; i<m_HasTextures_inverse.size(); ++i )
		{
			if( !m_HasTextures_inverse[i].expired() )
			{
				HasTextures_inverse_vec_obj->m_vec.push_back( shared_ptr<IfcIndexedTextureMap>( m_HasTextures_inverse[i] ) );
			}
		}
		vec_attributes_inverse.push_back( std::make_pair( "HasTextures_inverse", HasTextures_inverse_vec_obj ) );
	}
}
void IfcTessellatedFaceSet::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcTessellatedItem::setInverseCounterparts( ptr_self_entity );
}
void IfcTessellatedFaceSet::unlinkFromInverseCounterparts()
{
	IfcTessellatedItem::unlinkFromInverseCounterparts();
}