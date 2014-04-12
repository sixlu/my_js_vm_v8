
#include <stdio.h>
#include <string.h>
#include <libxml/HTMLparser.h>
#include <libxml/HTMLtree.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>

static htmlDocPtr html;

xmlXPathObjectPtr getElementByName(const char *name){

    xmlXPathContextPtr xpathCtx;
   
    if (name==NULL || (name!=NULL && strlen(name)==0))
       return NULL;

    #define PATHEXPRT_LEN 200
    char pathexpr[PATHEXPRT_LEN];
    memset(pathexpr,0,PATHEXPRT_LEN);
    sprintf(pathexpr,"//%s",name);
    const xmlChar* xpathExpr = pathexpr;

    /* Create xpath evaluation context */
    xpathCtx = xmlXPathNewContext(html);
    if(xpathCtx == NULL) {
        fprintf(stderr,"Error: unable to create new XPath context\n");
        xmlFreeDoc(html); 
        return NULL;
    }

    /* Evaluate xpath expression */
    xmlXPathObjectPtr xpathObj = xmlXPathEvalExpression(xpathExpr, xpathCtx);
    if(xpathObj == NULL) {
        fprintf(stderr,"Error: unable to evaluate xpath expression \"%s\"\n", xpathExpr);
        xmlXPathFreeContext(xpathCtx); 
        xmlFreeDoc(html); 
        return NULL;
    }

    return xpathObj;
}


void printAttr(xmlXPathObjectPtr xpathObj){

    if( xpathObj!=NULL){
        xmlNodeSetPtr nodes = xpathObj->nodesetval;
        int i=0;
        for(i=0;i<nodes->nodeNr;i++){
            xmlNodePtr node =  nodes->nodeTab[i];
            printf("%s content=======%s=======\n",node->name,node->children->content);
            struct _xmlAttr *property= node->properties;
            while(property!=NULL){
               printf("%s attribut[%s]=%s\n",node->name,property->name,property->children->content);
               property = property->next;
            } 
        }
    }
}


int main (int argc, char **argv) {
      const xmlChar *encoding;
      xmlNodePtr node;

      html=htmlParseFile(argv[1],NULL);
      if (html==NULL)
      {
         printf("htmlParseFile error\n"); 
         exit(1);
      }

      encoding=htmlGetMetaEncoding(html);
      printf("html[%s]'s encoding is %s\n",argv[1],encoding);

      xmlNodePtr root_node = xmlDocGetRootElement(html);

      xmlNodePtr first_node = xmlFirstElementChild(root_node);
      xmlNodePtr sibling_node = first_node;
      while(sibling_node!=NULL){

          printf("node's name[%s]\n",sibling_node->name);
          sibling_node=xmlNextElementSibling(sibling_node);
      }

      xmlXPathObjectPtr img_tags=getElementByName(argv[2]);
      printAttr(img_tags); 
      
}
