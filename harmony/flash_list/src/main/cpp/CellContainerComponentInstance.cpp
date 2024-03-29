#include "CellContainerComponentInstance.h"

namespace rnoh {

    CellContainerComponentInstance::CellContainerComponentInstance(Context context)
        : CppComponentInstance(std::move(context)) {}

    void CellContainerComponentInstance::onChildInserted(ComponentInstance::Shared const &childComponentInstance,
                                                         std::size_t index) {
        CppComponentInstance::onChildInserted(childComponentInstance, index);
        m_stackNode.insertChild(childComponentInstance->getLocalRootArkUINode(), index);
    }

    void CellContainerComponentInstance::onChildRemoved(ComponentInstance::Shared const &childComponentInstance) {
        CppComponentInstance::onChildRemoved(childComponentInstance);
        m_stackNode.removeChild(childComponentInstance->getLocalRootArkUINode());
    };

    StackNode &CellContainerComponentInstance::getLocalRootArkUINode() { return m_stackNode; }

    void CellContainerComponentInstance::setIndex(int const &index) { this->index = index; }
    int CellContainerComponentInstance::getIndex() { return index; }

    void CellContainerComponentInstance::setLeft(facebook::react::Float const &left) {
        m_layoutMetrics.frame.origin.x = left;
    }
    facebook::react::Float CellContainerComponentInstance::getLeft() { return m_layoutMetrics.frame.origin.x; }
    void CellContainerComponentInstance::setTop(facebook::react::Float const &top) {
        m_layoutMetrics.frame.origin.y = top;
    }
    facebook::react::Float CellContainerComponentInstance::getTop() { return m_layoutMetrics.frame.origin.y; }
    void CellContainerComponentInstance::setRight(facebook::react::Float const &right) {
        m_layoutMetrics.frame.origin.x = right - m_layoutMetrics.frame.size.width;
    }
    facebook::react::Float CellContainerComponentInstance::getRight() {
        return m_layoutMetrics.frame.origin.x + m_layoutMetrics.frame.size.width;
    }
    void CellContainerComponentInstance::setBottom(facebook::react::Float const &bottom) {
        m_layoutMetrics.frame.origin.y = bottom - m_layoutMetrics.frame.size.height;
    }
    facebook::react::Float CellContainerComponentInstance::getBottom() {
        return m_layoutMetrics.frame.origin.y + m_layoutMetrics.frame.size.height;
    }
    void CellContainerComponentInstance::setHeight(facebook::react::Float const &height) {
        m_layoutMetrics.frame.size.height = height;
    }
    facebook::react::Float CellContainerComponentInstance::getHeight() { return m_layoutMetrics.frame.size.height; }
    void CellContainerComponentInstance::setWidth(facebook::react::Float const &width) {
        m_layoutMetrics.frame.size.width = width;
    }
    facebook::react::Float CellContainerComponentInstance::getWidth() { return m_layoutMetrics.frame.size.width; }

    void CellContainerComponentInstance::onPropsChanged(SharedConcreteProps const &props) {
        CppComponentInstance::onPropsChanged(props);
        LOG(INFO) << "[clx] CellContainerComponentInstance::setProps" << props->index;
        this->setIndex(props->index);
    }

} // namespace rnoh