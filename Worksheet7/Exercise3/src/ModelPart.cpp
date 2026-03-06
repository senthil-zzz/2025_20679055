/**     @file ModelPart.cpp
  *
  *     EEEE2076 - Software Engineering & VR Project
  *
  *     Template for model parts that will be added as treeview items
  *
  *     P Evans 2022
  */

#include "ModelPart.h"


/* Commented out for now, will be uncommented later when you have
 * installed the VTK library
 */
#include <vtkSmartPointer.h>
#include <vtkDataSetMapper.h>
#include <vtkProperty.h>
#include <vtkPolyDataMapper.h>
#include <vtkSTLReader.h>


ModelPart::ModelPart(const QList<QVariant>& data, ModelPart* parent )
    : m_itemData(data), m_parentItem(parent) {
    isVisible = true;
    colourR = 255;
    colourG = 255;
    colourB = 255;
}


ModelPart::~ModelPart() {
    qDeleteAll(m_childItems);
}


void ModelPart::appendChild( ModelPart* item ) {
    item->m_parentItem = this;
    m_childItems.append(item);
}


ModelPart* ModelPart::child( int row ) {

    if (row < 0 || row >= m_childItems.size())
        return nullptr;
    return m_childItems.at(row);
}

int ModelPart::childCount() const {
    return m_childItems.count();
}


int ModelPart::columnCount() const {
    return m_itemData.count();
}

QVariant ModelPart::data(int column) const {
    if (column == 1) { // The "Visible?" column
        return isVisible ? "true" : "false"; // Show current status
    }

    if (column < 0 || column >= m_itemData.size())
        return QVariant();
    return m_itemData.at(column);
}


void ModelPart::set(int column, const QVariant &value) {
    if (column < 0 || column >= m_itemData.size())
        return;

    m_itemData.replace(column, value);
}


ModelPart* ModelPart::parentItem() {
    return m_parentItem;
}


int ModelPart::row() const {

    if (m_parentItem)
        return m_parentItem->m_childItems.indexOf(const_cast<ModelPart*>(this));
    return 0;
}

void ModelPart::setColour(const unsigned char R, const unsigned char G, const unsigned char B) {
    colourR = R;
    colourG = G;
    colourB = B;
}

unsigned char ModelPart::getColourR() {
    return colourR;
}

unsigned char ModelPart::getColourG() {
    return colourG;
}

unsigned char ModelPart::getColourB() {
    return colourB;
}

void ModelPart::setVisible(bool visibleState) {
    isVisible = visibleState;
}

bool ModelPart::visible() {
    return isVisible;
}

void ModelPart::loadSTL( QString fileName ) {
    // 1. Use the vtkSTLReader class to load the STL file
    this->file = vtkSmartPointer<vtkSTLReader>::New();
    this->file->SetFileName(fileName.toStdString().c_str());
    this->file->Update(); // Forces the reader to actually process the file

    // 2. Initialise the part's vtkMapper
    this->mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    this->mapper->SetInputConnection(this->file->GetOutputPort());

    // 3. Initialise the part's vtkActor and link to the mapper
    this->actor = vtkSmartPointer<vtkActor>::New();
    this->actor->SetMapper(this->mapper);

    // Apply the default colors and visibility we set in the constructor
    this->actor->GetProperty()->SetColor(colourR / 255.0, colourG / 255.0, colourB / 255.0);
    this->actor->SetVisibility(isVisible);
}

vtkSmartPointer<vtkActor> ModelPart::getActor() {
    // Return the smart pointer to the vtkActor to allow the part to be rendered
    return this->actor;
}

vtkActor* ModelPart::getNewActor() {
    // Return the smart pointer to the vtkActor to allow the part to be rendered
    return this->actor;// 1. Create new mapper
    vtkSmartPointer<vtkPolyDataMapper> newMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    newMapper->SetInputConnection(this->file->GetOutputPort());

    // 2. Create new actor and link to mapper
    vtkActor* newActor = vtkActor::New();
    newActor->SetMapper(newMapper);

    // 3. Link the vtkProperties of the original actor to the new actor.
    // This ensures GUI and VR share the exact same color/visibility settings!
    if (this->actor) {
        newActor->SetProperty(this->actor->GetProperty());
    }

    return newActor;
}

