/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkSpatialObjectWriter.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Insight Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __itkSpatialObjectWriter_h
#define __itkSpatialObjectWriter_h

#include "itkMetaSceneConverter.h"
#include "itkProcessObject.h"
#include "itkSpatialObject.h"
#include "itkSceneSpatialObject.h"


namespace itk
{

template <unsigned int NDimensions = 3, class PixelType = unsigned char>
class SpatialObjectWriter : public Object
{
public:

  /** SmartPointer typedef support */
  typedef SpatialObjectWriter Self;
  typedef SmartPointer<Self> Pointer;

  typedef SpatialObject<NDimensions> SpatialObjectType; 
  typedef SceneSpatialObject<NDimensions> SceneType; 

  /** Method for creation through the object factory */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  typedef Object Superclass;
  itkTypeMacro(Self, Superclass);


  /** Load a tube file. */
  void Update(void);

  /** Set the filename  */
  itkSetStringMacro(FileName);
  itkSetStringMacro(FullFileName);

  /** Get the filename */
  itkGetStringMacro(FileName);
  itkGetStringMacro(FullFileName);

  /** Set the Input  */
  void SetInput(SpatialObjectType * input){m_SpatialObject=input;}

  void SetInput(SceneType * input){m_Scene=input;}

protected:
  std::string m_FullFileName;
  std::string m_FileName;

  SpatialObjectWriter();
  virtual ~SpatialObjectWriter();

private:

  SpatialObjectType * m_SpatialObject;
  SceneType * m_Scene;

  MetaSceneConverter<NDimensions,PixelType> m_MetaToSpatialConverter;
};

} // namespace itk


#ifndef ITK_MANUAL_INSTANTIATION
#include "itkSpatialObjectWriter.txx"
#endif

#endif // __itkSpatialObjectWriter_h
