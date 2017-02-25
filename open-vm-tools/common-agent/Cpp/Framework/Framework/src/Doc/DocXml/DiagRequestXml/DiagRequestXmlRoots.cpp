/*
 *  Author: bwilliams
 *  Created: April 6, 2012
 *
 *  Copyright (C) 2012-2016 VMware, Inc.  All rights reserved. -- VMware Confidential
 *
 *  This code was generated by the script "build/dev/codeGen/genCppXml". Please
 *  speak to Brian W. before modifying it by hand.
 *
 */

#include "stdafx.h"

#include "Doc/DocXml/CafCoreTypesXml/RequestXml.h"
#include "Doc/DocXml/DiagRequestXml/DiagRequestXml.h"

#include "Doc/DiagRequestDoc/CDiagRequestDoc.h"
#include "Xml/XmlUtils/CXmlElement.h"
#include "Doc/DocXml/DiagRequestXml/DiagRequestXmlRoots.h"

using namespace Caf;

std::string XmlRoots::saveDiagRequestToString(
	const SmartPtrCDiagRequestDoc diagRequestDoc) {
	CAF_CM_STATIC_FUNC_VALIDATE("XmlRoots", "saveDiagRequestToString");

	std::string rc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(diagRequestDoc);

		const std::string schemaNamespace = DocXmlUtils::getSchemaNamespace("fx");
		const std::string schemaLocation = DocXmlUtils::getSchemaLocation("fx/DiagRequest.xsd");

		const SmartPtrCXmlElement rootXml = CXmlUtils::createRootElement(
			"diagRequest", schemaNamespace, schemaLocation);
		DiagRequestXml::add(diagRequestDoc, rootXml);

		rc = rootXml->saveToString();
	}
	CAF_CM_EXIT;

	return rc;
}

SmartPtrCDiagRequestDoc XmlRoots::parseDiagRequestFromString(
	const std::string xml) {
	CAF_CM_STATIC_FUNC_VALIDATE("XmlRoots", "parseDiagRequestFromString");

	SmartPtrCDiagRequestDoc diagRequestDoc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_STRING(xml);

		const SmartPtrCXmlElement rootXml = RequestXml::parseString(xml, "caf:diagRequest");
		diagRequestDoc = DiagRequestXml::parse(rootXml);
	}
	CAF_CM_EXIT;

	return diagRequestDoc;
}

void XmlRoots::saveDiagRequestToFile(
	const SmartPtrCDiagRequestDoc diagRequestDoc,
	const std::string filePath) {
	CAF_CM_STATIC_FUNC_LOG_VALIDATE("XmlRoots", "saveDiagRequestToFile");

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(diagRequestDoc);
		CAF_CM_VALIDATE_STRING(filePath);

		CAF_CM_LOG_DEBUG_VA1("Saving to file - %s", filePath.c_str());

		const std::string diagRequestStr =
			saveDiagRequestToString(diagRequestDoc);
		FileSystemUtils::saveTextFile(filePath, diagRequestStr);
	}
	CAF_CM_EXIT;
}

SmartPtrCDiagRequestDoc XmlRoots::parseDiagRequestFromFile(
	const std::string filePath) {
	CAF_CM_STATIC_FUNC_VALIDATE("XmlRoots", "parseDiagRequestFromFile");

	SmartPtrCDiagRequestDoc diagRequestDoc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_STRING(filePath);

		const SmartPtrCXmlElement rootXml = RequestXml::parseFile(filePath, "caf:diagRequest");
		diagRequestDoc = DiagRequestXml::parse(rootXml);
	}
	CAF_CM_EXIT;

	return diagRequestDoc;
}